#include <graph/display.hpp>
#include <sstream>
Graph::Display::Display(char **av, int ac) : app(NULL), scene(NULL), view(NULL),
					     _map(NULL), _usrs(NULL), _timeUnit(0),
					     _lastPos(-1, -1)
{
  app = new QApplication(ac, av);


  QTimer::singleShot(1, app, SLOT(quit()));
  app->setFont(QFont("Arial", 14, QFont::Bold));
  app->exec();
  scene = new MyGraphicsScene();
  view = new QGraphicsView(scene);
  scene->setSceneRect(0, 0, 1200, 720);
  view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
  view->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
  view->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
  view->setMinimumSize(1200, 720);
  view->setBaseSize(1200, 720);
  view->show();
  app->processEvents();
  this->createArrMemPtr();
  this->engine = irrklang::createIrrKlangDevice();

}

void Graph::Display::createArrMemPtr(void)
{
  this->_arrPtrMemb.insert(std::make_pair("msz", &Graph::Display::mszFunc));
  this->_arrPtrMemb.insert(std::make_pair("bct", &Graph::Display::bctFunc));
  this->_arrPtrMemb.insert(std::make_pair("pnw", &Graph::Display::pnwFunc));
  this->_arrPtrMemb.insert(std::make_pair("tna", &Graph::Display::tnaFunc));
  this->_arrPtrMemb.insert(std::make_pair("ppo", &Graph::Display::ppoFunc));
  this->_arrPtrMemb.insert(std::make_pair("plv", &Graph::Display::plvFunc));
  this->_arrPtrMemb.insert(std::make_pair("pin", &Graph::Display::pinFunc));
  this->_arrPtrMemb.insert(std::make_pair("pex", &Graph::Display::pexFunc));
  this->_arrPtrMemb.insert(std::make_pair("pbc", &Graph::Display::pbcFunc));
  this->_arrPtrMemb.insert(std::make_pair("pic", &Graph::Display::picFunc));
  this->_arrPtrMemb.insert(std::make_pair("pie", &Graph::Display::pieFunc));
  this->_arrPtrMemb.insert(std::make_pair("pfk", &Graph::Display::pfkFunc));
  this->_arrPtrMemb.insert(std::make_pair("pgt", &Graph::Display::pgtFunc));
  this->_arrPtrMemb.insert(std::make_pair("pdr", &Graph::Display::pdrFunc));
  this->_arrPtrMemb.insert(std::make_pair("pdi", &Graph::Display::pdiFunc));
  this->_arrPtrMemb.insert(std::make_pair("enw", &Graph::Display::enwFunc));
  this->_arrPtrMemb.insert(std::make_pair("eht", &Graph::Display::ehtFunc));
  this->_arrPtrMemb.insert(std::make_pair("ebo", &Graph::Display::eboFunc));
  this->_arrPtrMemb.insert(std::make_pair("edi", &Graph::Display::ediFunc));
  this->_arrPtrMemb.insert(std::make_pair("seg", &Graph::Display::segFunc));
  this->_arrPtrMemb.insert(std::make_pair("sgt", &Graph::Display::sgtFunc));
}

Graph::Display::~Display()
{
  app->closeAllWindows();
  if (this->_map)
    delete this->_map;
  if (this->_usrs)
    delete this->_usrs;
  delete scene;
  delete view;
  delete app;
  app = NULL;
}

void Graph::Display::clickCenterView()
{
  QPointF	tmpPos;
  QPointF	mousePos;

  mousePos = this->scene->getPos();
  if (mousePos.x() < 0 || mousePos.y() < 0)
  {
    this->_map->rmBlockNfo();
    return;
  }
  tmpPos.setX(mousePos.x() / 64);
  tmpPos.setY(mousePos.y() / 64);
  if (tmpPos == this->_lastPos)
    return;
  this->view->centerOn(this->scene->getPos());

  this->_map->rmBlockNfo();
  this->_map->addBlockNfo(static_cast<int>(tmpPos.x()), static_cast<int>(tmpPos.y()));
  this->_lastPos = tmpPos;
}

bool Graph::Display::display(void)
{
  if (this->app->closingDown() == true)
    return false;

  if (this->view->isActiveWindow() == false && this->view->isHidden() == true)
    return false;
  if (this->_map)
  {
    this->clickCenterView();
    this->_map->changePosBlockNfo(this->view->mapToScene(this->view->viewport()->rect().center()));
  }
  this->app->processEvents();
  return true;
}

void Graph::Display::processLine(const std::string &line)
{
  bool		haveValidCmd = false;
  std::string	myLine = line;
  std::map<int, std::string>	arrArgs;

  this->epurStr(myLine);
  //std::cout << myLine << std::endl;
  arrArgs = this->getArgs(myLine);
  if (this->_usrs && this->_usrs->isHaveWinner())
  {
    QMessageBox::information(0, "Game terminated", "this game is terminated please quit the window");
    return ;
  }
  for (auto & elem : this->_arrPtrMemb)
  {
    if (elem.first == arrArgs[0])
    {
      haveValidCmd = true;
      try
      {
	if (!(this->*(elem.second))(arrArgs))
	  std::cerr << "Detect error exec cmd" << std::endl;
      }
      catch (...)
      {
	std::exception_ptr ex = std::current_exception();
	try
	{
	  if (ex)
	    std::rethrow_exception(ex);
	}
	catch (std::invalid_argument ex)
	{
	  std::cout << "ERROR : please enter numeric parameter" << std::endl;
	}
      }
    }
  }
  if (!haveValidCmd)
    std::cout << "Error : invalid command : " << arrArgs[0] << std::endl;
}


void Graph::Display::epurStr(std::string &s)
{
  bool space = false;
  auto p = s.begin();

  for (auto ch : s)
  {
    if (std::isspace(ch))
    {
      space = p != s.begin();
    }
    else
    {
      if (space) *p++ = ' ';
      *p++ = ch;
      space = false;
    }
  }
  s.erase(p, s.end());
}

std::map<int, std::string> Graph::Display::getArgs(const std::string &line)
{
  std::map<int, std::string>	arrArgs;
  std::stringstream		lineToSplit;
  std::string			tmp;
  int				cpt;

  cpt = 0;
  lineToSplit.str(line);
  while (std::getline(lineToSplit, tmp, ' '))
  {
    arrArgs[cpt] = tmp;
    cpt++;
  }
  if (std::getline(lineToSplit, tmp, '\n'))
  {
    arrArgs[cpt] = tmp;
  }
  return arrArgs;
}

bool Graph::Display::mszFunc(const std::map<int, std::string> &args)
{
  irrklang::ISound* mySound;

  if (args.size() == 3)
  {
    if (std::stoi(args.at(1)) > 0 && std::stoi(args.at(2)) > 0)
    {
      if (this->_map)
	delete this->_map;
      if (this->_usrs)
	delete this->_usrs;
      mySound = this->engine->play2D("./media/sound/main.wav", true , false, true);
      if (mySound)
      {
	mySound->setVolume(0.1);
      }
      this->_map = new Graph::Map::MapBlocks(this->scene, std::stoi(args.at(1)), std::stoi(args.at(2)), this->_timeUnit);
      this->_usrs = new Graph::User::UsrManage(this->scene, this->_timeUnit);
    }
    else
    {
      std::cerr << "msz : Bad number for width or height" << std::endl;
      return false;
    }

  }
  else
    {
      std::cerr << "msz : Bad number of parameters" << std::endl;
      return false;
    }

  return true;
}

bool Graph::Display::bctFunc(const std::map<int, std::string> &args)
{
  int x;
  int y;

  if (!this->_map)
  {
    std::cerr << "Map not initialize" << std::endl;
    return (false);
  }
  if (args.size() == 10)
  {
    if (std::stoi(args.at(1)) >= 0 && std::stoi(args.at(2)) >= 0)
    {
      x = std::stoi(args.at(1));
      y = std::stoi(args.at(2));
      if (x >= 0 && x < this->_map->getWidth() && y >= 0 && y < this->_map->getHeight())
      {
	int tab[7] = {std::stoi(args.at(3)), std::stoi(args.at(4)),
		      std::stoi(args.at(5)),
		      std::stoi(args.at(6)),
		      std::stoi(args.at(7)),
		      std::stoi(args.at(8)),
		      std::stoi(args.at(9))};
	this->_map->placeRessources(x, y, tab);
      }
      else
      {
	std::cerr << "bct : case out of range" << std::endl;
	return false;
      }
    }
    else
    {
      std::cerr << "bct : Bad number for width or height" << std::endl;
      return false;
    }

  }
  else
  {
    std::cerr << "bct : Bad number of parameters" << std::endl;
    return false;
  }

  return true;
}

bool Graph::Display::pnwFunc(const std::map<int, std::string> &args)
{
  int x;
  int y;

  if (!this->_map)
  {
    std::cerr << "Map not initialize" << std::endl;
    return (false);
  }
  if (args.size() == 7)
  {
    if (std::stoi(args.at(2)) >= 0 && std::stoi(args.at(3)) >= 0)
    {
      x = std::stoi(args.at(2));
      y = std::stoi(args.at(3));
      if (x >= 0 && x < this->_map->getWidth() && y >= 0 && y < this->_map->getHeight())
	this->_usrs->addPlayer(std::stoi(args.at(1)), x, y, std::stoi(args.at(4)), std::stoi(args.at(5)), args.at(6));
      else
      {
	std::cerr << "pwn : case out of range" << std::endl;
	return false;
      }
    }
    else
    {
      std::cerr << "pwn : Bad number for width or height" << std::endl;
      return false;
    }

  }
  else
  {
    std::cerr << "pwn : Bad number of parameters" << std::endl;
    return false;
  }

  return true;
}

bool Graph::Display::tnaFunc(const std::map<int, std::string> &args)
{

  if (!this->_map)
  {
    std::cerr << "Map not initialize" << std::endl;
    return (false);
  }
  if (args.size() == 2)
  {
   this->_usrs->addTeam(args.at(1));
  }
  else
  {
    std::cerr << "tna : Bad number of parameters" << std::endl;
    return false;
  }

  return true;
}

bool Graph::Display::ppoFunc(const std::map<int, std::string> &args)
{
  int x;
  int y;

  if (!this->_map)
  {
    std::cerr << "Map not initialize" << std::endl;
    return (false);
  }
  if (args.size() == 5)
  {
    if (std::stoi(args.at(2)) >= 0 && std::stoi(args.at(3)) >= 0)
    {
      x = std::stoi(args.at(2));
      y = std::stoi(args.at(3));
      if (x >= 0 && x < this->_map->getWidth() && y >= 0 && y < this->_map->getHeight())
	this->_usrs->movePlayer(std::stoi(args.at(1)), x, y, std::stoi(args.at(4)));
      else
      {
	std::cerr << "ppo : case out of range" << std::endl;
	return false;
      }
    }
    else
    {
      std::cerr << "ppo : Bad number for width or height" << std::endl;
      return false;
    }

  }
  else
  {
    std::cerr << "ppo : Bad number of parameters" << std::endl;
    return false;
  }

  return true;
}

bool Graph::Display::plvFunc(const std::map<int, std::string> &args)
{
  if (!this->_map)
  {
    std::cerr << "Map not initialize" << std::endl;
    return (false);
  }
  if (args.size() == 3)
  {
    this->_usrs->changePlayerTeam(std::stoi(args.at(1)), std::stoi(args.at(2)));
  }
  else
  {
    std::cerr << "plv : Bad number of parameters" << std::endl;
    return false;
  }

  return true;
}

bool Graph::Display::pinFunc(const std::map<int, std::string> & args)
{
  int x;
  int y;

  if (!this->_map)
  {
    std::cerr << "Map not initialize" << std::endl;
    return (false);
  }
  if (args.size() == 11)
  {
    if (std::stoi(args.at(2)) >= 0 && std::stoi(args.at(3)) >= 0)
    {
      x = std::stoi(args.at(2));
      y = std::stoi(args.at(3));
      if (x >= 0 && x < this->_map->getWidth() && y >= 0 && y < this->_map->getHeight())
      {
	int tab[7] = {std::stoi(args.at(4)), std::stoi(args.at(5)),
		      std::stoi(args.at(6)),
		      std::stoi(args.at(7)),
		      std::stoi(args.at(8)),
		      std::stoi(args.at(9)),
		      std::stoi(args.at(10))};
	this->_usrs->setPlayerInvt(std::stoi(args.at(1)), x, y, tab);
      }
      else
      {
	std::cerr << "pin : case out of range" << std::endl;
	return false;
      }
    }
    else
    {
      std::cerr << "pin : Bad number for width or height" << std::endl;
      return false;
    }

  }
  else
  {
    std::cerr << "pin : Bad number of parameters" << std::endl;
    return false;
  }

  return true;
}

bool Graph::Display::pexFunc(const std::map<int, std::string> &args)
{
  if (!this->_map)
  {
    std::cerr << "Map not initialize" << std::endl;
    return (false);
  }
  if (args.size() == 2)
  {
  }
  else
  {
    std::cerr << "pex : Bad number of parameters" << std::endl;
    return false;
  }

  return true;
}

bool Graph::Display::pbcFunc(const std::map<int, std::string> &args)
{
  if (!this->_map)
  {
    std::cerr << "Map not initialize" << std::endl;
    return (false);
  }
  if (args.size() >= 3)
  {
    this->_usrs->addBroadcast(std::stoi(args.at(1)));
  }
  else
  {
    std::cerr << "pbc : Bad number of parameters" << std::endl;
    return false;
  }

  return true;
}

bool Graph::Display::picFunc(const std::map<int, std::string> &args)
{
  int x;
  int y;

  if (!this->_map)
  {
    std::cerr << "Map not initialize" << std::endl;
    return (false);
  }
  if (args.size() <= 5)
  {
    x = std::stoi(args.at(1));
    y = std::stoi(args.at(2));
    if (x >= 0 && x < this->_map->getWidth() && y >= 0 && y < this->_map->getHeight())
    {
      this->_map->launchIncant(x, y, std::stoi(args.at(3)));
      this->_usrs->startIncantBroadcast(args);
    }
    else
    {
      std::cerr << "pic : Bad number for width or height" << std::endl;
      return false;
    }
  }
  else
  {
    std::cerr << "pic : Bad number of parameters" << std::endl;
    return false;
  }

  return true;
}

bool Graph::Display::pieFunc(const std::map<int, std::string> &args)
{
  int x;
  int y;

  if (!this->_map)
  {
    std::cerr << "Map not initialize" << std::endl;
    return (false);
  }
  if (args.size() == 4)
  {
    x = std::stoi(args.at(1));
    y = std::stoi(args.at(2));
    if (x >= 0 && x < this->_map->getWidth() && y >= 0 && y < this->_map->getHeight())
    {
      if (args.at(3) == "1")
	this->_map->incantOk(x, y);
      if (args.at(3) == "0")
	this->_map->incantKO(x, y);
    }
    else
    {
      std::cerr << "pie : Bad number for width or height" << std::endl;
      return false;
    }
  }
  else
  {
    std::cerr << "pie : Bad number of parameters" << std::endl;
    return false;
  }

  return true;
}

bool Graph::Display::pfkFunc(const std::map<int, std::string> &args)
{
  if (!this->_map)
  {
    std::cerr << "Map not initialize" << std::endl;
    return (false);
  }
  if (args.size() == 2)
  {
  }
  else
  {
    std::cerr << "pfk : Bad number of parameters" << std::endl;
    return false;
  }

  return true;
}

bool Graph::Display::pdrFunc(const std::map<int, std::string> &args)
{
  if (!this->_map)
  {
    std::cerr << "Map not initialize" << std::endl;
    return (false);
  }
  if (args.size() == 3)
  {
    this->_usrs->removeRessource(std::stoi(args.at(1)), std::stoi(args.at(2)));
  }
  else
  {
    std::cerr << "pdr : Bad number of parameters" << std::endl;
    return false;
  }

  return true;
}

bool Graph::Display::pgtFunc(const std::map<int, std::string> &args)
{
  if (!this->_map)
  {
    std::cerr << "Map not initialize" << std::endl;
    return (false);
  }
  if (args.size() == 3)
  {
    this->_usrs->addRessource(std::stoi(args.at(1)), std::stoi(args.at(2)));
  }
  else
  {
    std::cerr << "pgt : Bad number of parameters" << std::endl;
    return false;
  }

  return true;
}

bool Graph::Display::pdiFunc(const std::map<int, std::string> &args)
{
  if (!this->_map)
  {
    std::cerr << "Map not initialize" << std::endl;
    return (false);
  }
  if (args.size() == 2)
  {
    this->_usrs->killPlayer(std::stoi(args.at(1)));
  }
  else
  {
    std::cerr << "pdi : Bad number of parameters" << std::endl;
    return false;
  }

  return true;
}

bool Graph::Display::enwFunc(const std::map<int, std::string> &args)
{
  int x;
  int y;

  if (!this->_map)
  {
    std::cerr << "Map not initialize" << std::endl;
    return (false);
  }
  if (args.size() <= 5)
  {
    x = std::stoi(args.at(3));
    y = std::stoi(args.at(4));
    if (x >= 0 && x < this->_map->getWidth() && y >= 0 && y < this->_map->getHeight())
    {
      this->_usrs->dropEgg(std::stoi(args.at(1)), std::stoi(args.at(2)), x, y);
    }
    else
    {
      std::cerr << "enw : Bad number for width or height" << std::endl;
      return false;
    }
  }
  else
  {
    std::cerr << "enw : Bad number of parameters" << std::endl;
    return false;
  }

  return true;
}

bool Graph::Display::ehtFunc(const std::map<int, std::string> &args)
{
  if (!this->_map)
  {
    std::cerr << "Map not initialize" << std::endl;
    return (false);
  }
  if (args.size() == 2)
  {
    this->_usrs->bornEgg(std::stoi(args.at(1)));
  }
  else
  {
    std::cerr << "eht : Bad number of parameters" << std::endl;
    return false;
  }

  return true;
}

bool Graph::Display::eboFunc(const std::map<int, std::string> &args)
{
  if (!this->_map)
  {
    std::cerr << "Map not initialize" << std::endl;
    return (false);
  }
  if (args.size() == 2)
  {
    //this->_usrs->killPlayer(std::stoi(args.at(1)));
  }
  else
  {
    std::cerr << "ebo : Bad number of parameters" << std::endl;
    return false;
  }

  return true;
}

bool Graph::Display::ediFunc(const std::map<int, std::string> &args)
{
  if (!this->_map)
  {
    std::cerr << "Map not initialize" << std::endl;
    return (false);
  }
  if (args.size() == 2)
  {
    this->_usrs->killEgg(std::stoi(args.at(1)));
  }
  else
  {
    std::cerr << "edi : Bad number of parameters" << std::endl;
    return false;
  }

  return true;
}

bool Graph::Display::segFunc(const std::map<int, std::string> &args)
{
  if (!this->_map)
  {
    std::cerr << "Map not initialize" << std::endl;
    return (false);
  }
  if (args.size() == 2)
  {
    this->_usrs->printWinner(args.at(1));
  }
  else
  {
    std::cerr << "seg : Bad number of parameters" << std::endl;
    return false;
  }

  return true;
}

bool Graph::Display::sgtFunc(const std::map<int, std::string> &args)
{
  if (!this->_map)
  {
    std::cerr << "Map not initialize" << std::endl;
    return (false);
  }
  if (args.size() == 2)
  {
    this->_usrs->setTimeUnit(std::stof(args.at(1)));
    this->_map->setTimeUnit(std::stof(args.at(1)));
  }
  else
  {
    std::cerr << "sgt : Bad number of parameters" << std::endl;
    return false;
  }

  return true;
}


