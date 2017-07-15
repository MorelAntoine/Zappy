#include "graph/user_manage.hpp"

Graph::User::UsrManage::UsrManage(QGraphicsScene *scene, const float timeUnit) : _scene(scene), haveWinner(false), _timeUnit(timeUnit)
{
this->initSprite();
}

Graph::User::UsrManage::~UsrManage()
{
}

void Graph::User::UsrManage::initSprite(void)
{
  for (int team = 1; team < 5; team++)
  {
    for (int lvl = 1; lvl < 9; lvl++)
    {
      this->spritePlayer[team - 1][lvl - 1] = this->getSprites(4, std::string("./media/player/" + std::to_string(team) + std::to_string(lvl) + ".png"));
    }
  }

  this->spriteEgg = this->getSprites(2, std::string("./media/anim/ballanim-1.png"));
  this->spriteEggOK = this->getSprites(1, std::string("./media/anim/ballborn-1.png"));
  this->spriteEggKO = this->getSprites(1, std::string("./media/anim/balldie-1.png"));
  this->spriteAnimation[BROADCAST] = this->getSprites(2, std::string("./media/anim/broadcast.png"));
  this->spriteAddRes = this->getSprites(1, std::string("./media/anim/add.png"));
  this->spriteDelRes = this->getSprites(1, std::string("./media/anim/del.png"));
  this->spriteDeath = this->getSprites(1, std::string("./media/anim/death.png"));
}

QList<QPixmap> Graph::User::UsrManage::getSprites(int nbSprite, std::string image)
{
  int			subImageHeight;
  QImage		img;
  QList<QPixmap>	res;

  img.load(image.c_str());
  subImageHeight = img.height() / nbSprite;
  for (int i = 0; i < nbSprite; i++)
  {
    QImage subImage = img.copy(0, i * subImageHeight, img.width(), subImageHeight);
    res.push_back(QPixmap::fromImage(subImage));
  }
  return res;
}

void Graph::User::UsrManage::checkUser(std::list<t_User> &list)
{
  for (auto it = list.begin(); it!= list.end();)
  {
    if ((*it).anim && (*it).anim->getIsEnd() == true)
    {
      (*it).anim->ending();
      delete (*it).anim;
      (*it).anim = NULL;
      if ((*it).isDead)
      {
	delete (*it).spritePlayer;
	this->_usrs.erase(it);
	this->checkUser(list);
	return;
      }
    }
    ++it;
  }
}


Graph::User::t_User
Graph::User::UsrManage::initEntity(const int id, const int x, const int y, const int lvl, const int orient, const std::string &team, bool PlOrEgg)
{
  t_User	newUser;
  int		cptTeam = 0;

  newUser.id = id;
  newUser.x = x;
  newUser.y = y;
  newUser.lvl = lvl;
  newUser.orient = orient;
  newUser.isDead = false;
  newUser.teamNb = -1;
  newUser.teamName = std::string("");
  newUser.spritePlayer = NULL;
  newUser.anim = NULL;
  for (auto tmpTeam : this->_teams)
  {
    if (tmpTeam == team)
    {
      newUser.teamNb = cptTeam;
      newUser.teamName = tmpTeam;
    }
    cptTeam++;
  }
  if (newUser.teamNb == -1)
  {
    std::cerr << "Team not exist" << std::endl;
    newUser.isDead = true;
    return newUser;
  }
  if (7 < lvl || 4 < orient || lvl < 1 || orient < 1)
  {
    std::cerr << "Bad number of lvl or orientation" << std::endl;
    newUser.isDead = true;
    return newUser;
  }
  if (PlOrEgg)
  {
    newUser.spritePlayer = this->_scene->addPixmap(this->spritePlayer[newUser.teamNb % 4][lvl - 1].at(orient - 1));
    newUser.spritePlayer->setPos(x * SIZEOFBLOCK + USRMARGINW, y * SIZEOFBLOCK + USRMARGINH);
    newUser.spritePlayer->setZValue(2);
  }
  else
  {
    newUser.anim = new AnimatedLabel(42000 / this->_timeUnit,
				     500 / this->_timeUnit, 2, &this->spriteEgg, this->_scene);
    newUser.widget = this->_scene->addWidget(newUser.anim);
    newUser.anim->setAnimPos(newUser.x * SIZEOFBLOCK, newUser.y * SIZEOFBLOCK);
  }

  return newUser;
}

void
Graph::User::UsrManage::addPlayer(const int id, const int x, const int y, const int orient,
				  int lvl, const std::string & team)
{
  t_User		newUser;

  this->checkUser(this->_usrs);
  for (auto & usr : this->_usrs)
  {
    if (usr.id == id)
    {
      std::cerr << "User already exit" << std::endl;
      return;
    }
  }
  newUser = this->initEntity(id, x, y, lvl, orient, team, true);
  if (newUser.isDead == true)
    return;
  this->_usrs.push_back(newUser);
}

void Graph::User::UsrManage::addTeam(const std::string &team)
{
  for (auto &it : this->_teams)
  {
    if (it == team)
    {
      std::cerr << "Team already exist" << std::endl;
      return;
    }
  }
  this->_teams.push_back(team);
}

void Graph::User::UsrManage::movePlayer(const int id, const int x, const int y, const int orient)
{
  bool		havePlayer = false;
  for (auto &it : this->_usrs)
  {
    if (it.id == id)
    {
      havePlayer = true;
      if (4 < orient)
      {
	std::cerr << "Bad number of orientation" << std::endl;
	return;
      }
      it.orient = orient;
      it.x = x;
      it.y = y;
      it.spritePlayer->setPixmap(this->spritePlayer[it.teamNb % 4][it.lvl - 1].at(orient - 1));
      it.spritePlayer->setPos(x * SIZEOFBLOCK + USRMARGINW, y * SIZEOFBLOCK + USRMARGINH);
      if (it.anim)
	it.anim->setGeometry(x * SIZEOFBLOCK, y * SIZEOFBLOCK, SIZEOFBLOCK, SIZEOFBLOCK);
    }
  }
  if (havePlayer == false)
    std::cerr << "Player not exist" << std::endl;
}

void Graph::User::UsrManage::changePlayerTeam(const int id, const int lvl)
{
  bool		havePlayer = false;
  for (auto &it : this->_usrs)
  {
    if (it.id == id)
    {
      havePlayer = true;
      if (lvl > 7)
      {
	std::cerr << "Bad number of level" << std::endl;
	return;
      }
      it.lvl = lvl;
      it.spritePlayer->setPixmap(this->spritePlayer[it.teamNb % 4][it.lvl - 1].at(it.orient - 1));
    }
  }
  if (havePlayer == false)
    std::cerr << "Player not exist" << std::endl;
}

void Graph::User::UsrManage::setPlayerInvt(const int id, const int x, const int y,
					   const int *inv)
{
  bool		havePlayer = false;
  int		xx;
  int		yy;

  xx = x;
  yy = y;
  xx = yy;
  yy = xx;
  for (auto &it : this->_usrs)
  {
    if (it.id == id)
    {
      havePlayer = true;
      for (int i = 0; i < 7; i++)
      {
	if (inv[i] < 0)
	{
	  std::cerr << "inventory ressource is negative" << std::endl;
	  return;
	}
	it.inventory[i] = inv[i];
      }
    }
  }
  if (havePlayer == false)
    std::cerr << "Player not exist" << std::endl;
}

void Graph::User::UsrManage::addBroadcast(const int id)
{
  bool		havePlayer = false;

  this->checkUser(this->_usrs);

  for (auto &it : this->_usrs)
  {
    if (it.id == id)
    {
      havePlayer = true;
      it.anim = new AnimatedLabel(7000 / this->_timeUnit, 500 / this->_timeUnit, 4, &this->spriteAnimation[BROADCAST], this->_scene);
      it.widget = this->_scene->addWidget(it.anim);
      it.anim->setAnimPos(it.x * SIZEOFBLOCK, it.y * SIZEOFBLOCK);
    }
  }
  if (havePlayer == false)
    std::cerr << "Player not exist" << std::endl;
}

void Graph::User::UsrManage::startIncantBroadcast(const std::map<int, std::string> &args)
{
  bool		havePlayer = false;
  int		idTmp;

  this->checkUser(this->_usrs);

  for (unsigned int i = 4; i < args.size(); i++)
  {
    for (auto &it : this->_usrs)
    {
      idTmp = std::stoi(args.at(i));
      if (it.id == idTmp)
      {
	havePlayer = true;
	it.anim = new AnimatedLabel(300000 / this->_timeUnit, 200 / this->_timeUnit, 3, &this->spritePlayer[it.teamNb % 4][it.lvl - 1], this->_scene);
	it.widget = this->_scene->addWidget(it.anim);
	it.anim->setAnimPos(it.x * SIZEOFBLOCK + USRMARGINW, it.y * SIZEOFBLOCK + USRMARGINH);
      }
    }
    if (havePlayer == false)
    {
      std::cerr << "Player not exist" << std::endl;
      return;
    }
  }
}

void Graph::User::UsrManage::addRessource(const int id, const int res)
{
  bool		havePlayer = false;

  this->checkUser(this->_usrs);

  for (auto &it : this->_usrs)
  {
    if (it.id == id)
    {
      havePlayer = true;
      if (res > 0 && res <= 7)
      {
	it.inventory[res]++;
	it.anim = new AnimatedLabel(7000 / this->_timeUnit, 7000 / this->_timeUnit, 3, &this->spriteAddRes, this->_scene);
	it.widget = this->_scene->addWidget(it.anim);
	it.anim->setAnimPos(it.x * SIZEOFBLOCK + 5, it.y * SIZEOFBLOCK + 5);
      }
    }
  }
  if (havePlayer == false)
  {
    std::cerr << "Player not exist" << std::endl;
    return;
  }
}

void Graph::User::UsrManage::removeRessource(const int id, const int res)
{
  bool		havePlayer = false;

  this->checkUser(this->_usrs);

  for (auto &it : this->_usrs)
  {
    if (it.id == id)
    {
      havePlayer = true;
      if (res > 0 && res <= 7)
      {
	it.inventory[res]++;
	it.anim = new AnimatedLabel(7000 / this->_timeUnit, 7000 / this->_timeUnit, 3, &this->spriteDelRes, this->_scene);
	it.widget = this->_scene->addWidget(it.anim);
	it.anim->setAnimPos(it.x * SIZEOFBLOCK + 5, it.y * SIZEOFBLOCK + 5);
      }
    }
  }
  if (havePlayer == false)
  {
    std::cerr << "Player not exist" << std::endl;
    return;
  }
}

void Graph::User::UsrManage::killPlayer(const int id)
{
  bool		havePlayer = false;

  this->checkUser(this->_usrs);

  for (auto &it : this->_usrs)
  {
    if (it.id == id)
    {
      havePlayer = true;

      it.anim = new AnimatedLabel(1000 / this->_timeUnit, 1000 / this->_timeUnit, 2, &this->spriteDeath, this->_scene);
      it.widget = this->_scene->addWidget(it.anim);
      it.anim->setAnimPos(it.x * SIZEOFBLOCK, it.y * SIZEOFBLOCK);
      it.spritePlayer->setVisible(false);
      it.isDead = true;
    }
  }
  if (havePlayer == false)
  {
    std::cerr << "Player not exist" << std::endl;
    return;
  }
}

void Graph::User::UsrManage::dropEgg(const int idEgg, const int idPlayer, const int x, const int y)
{
  bool		havePlayer = false;
  t_Egg		newEgg;

  this->checkUser(this->_usrs);
  this->checkUser(this->_eggs);
  for (auto &it : this->_usrs)
  {
    if (it.id == idPlayer)
    {
      havePlayer = true;
      for (auto &itEgg : this->_eggs)
      {
	if (itEgg.id == idEgg)
	{
	  std::cerr << "Egg already in this server" << std::endl;
	  return;
	}
      }
      newEgg = this->initEntity(idEgg, x, y, it.lvl, it.orient, it.teamName, false);
      if (newEgg.isDead)
	return;
      this->_eggs.push_back(newEgg);
    }
  }
  if (havePlayer == false)
  {
    std::cerr << "Player not exist" << std::endl;
    return;
  }
}

void Graph::User::UsrManage::killEgg(const int id)
{
  bool	haveEgg = false;

  this->checkUser(this->_eggs);
  for (auto &it : this->_eggs)
  {
    if (it.id == id)
    {
      haveEgg = true;
      if (it.anim)
	it.anim->ending();
      if (it.anim)
	delete it.anim;
      it.anim = new AnimatedLabel(1000 / this->_timeUnit, 1000 / this->_timeUnit, 2, &this->spriteEggKO, this->_scene);
      it.widget = this->_scene->addWidget(it.anim);
      it.anim->setAnimPos(it.x * SIZEOFBLOCK, it.y * SIZEOFBLOCK);
      it.isDead = true;
    }
  }
  if (haveEgg == false)
  {
    std::cerr << "Egg not exist" << std::endl;
    return;
  }
}

void Graph::User::UsrManage::bornEgg(const int id)
{
  bool	haveEgg = false;

  this->checkUser(this->_eggs);
  for (auto &it : this->_eggs)
  {
    if (it.id == id)
    {
      haveEgg = true;
      it.anim->ending();
      if (it.anim)
	delete it.anim;
      it.anim = new AnimatedLabel(1000 / this->_timeUnit, 500 / this->_timeUnit, 5, &this->spriteEggOK, this->_scene);
      it.widget = this->_scene->addWidget(it.anim);
      it.anim->setAnimPos(it.x * SIZEOFBLOCK, it.y * SIZEOFBLOCK);
      it.isDead = true;
    }
  }
  if (haveEgg == false)
  {
    std::cerr << "Egg not exist" << std::endl;
    return;
  }
}

void Graph::User::UsrManage::printWinner(const std::string &team)
{
  bool	haveTeam = false;

  for (auto &it : this->_teams)
  {
    if (it == team)
    {
      this->haveWinner = true;
      haveTeam = true;
      QMessageBox::information(0, "End of game", std::string("The game is terminated the winner is : " + team).c_str());
    }
  }
  if (haveTeam == false)
  {
    std::cerr << "Team not exist" << std::endl;
    return;
  }
}

bool Graph::User::UsrManage::isHaveWinner() const
{
  return haveWinner;
}

void Graph::User::UsrManage::setTimeUnit(float timeUnit)
{
  if (timeUnit == 0)
    _timeUnit = 1;
  else
  _timeUnit = timeUnit;
}




