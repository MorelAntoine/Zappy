#include	<iostream>
#include	"graph/mapblock.hpp"
Graph::Map::MapBlocks::MapBlocks(QGraphicsScene *scene, const int &w, const int &h, const float timeUnit) : _width(w), _height(h), _scene(scene),
													    _timeUnit(timeUnit), _blockNfo(NULL)
{
  int		pos = 0;

  this->initSprites();

  scene->setSceneRect(-SIZEOFBLOCK, -SIZEOFBLOCK, w * SIZEOFBLOCK + 2 * SIZEOFBLOCK, h * SIZEOFBLOCK + 2 * SIZEOFBLOCK);
  this->createSquareBox();
  for (int x = 0; x < w * SIZEOFBLOCK; x += SIZEOFBLOCK)
  {
    for (int y = 0; y < _height * SIZEOFBLOCK; y += SIZEOFBLOCK)
    {
      pos = (y / SIZEOFBLOCK) * w + (x / SIZEOFBLOCK);
      this->_map[pos].imgGraph =  this->_scene->addPixmap(*this->spriteGrass);
      this->_map[pos].imgGraph->setPos(x, y);
      this->_map[pos].imgGraph->setZValue(0);
      this->_map[pos].lvlIncant = -1;
      this->_map[pos].anim = NULL;
      this->_map[pos].widget = NULL;
    }
  }
}

void Graph::Map::MapBlocks::createSquareBox(void)
{
  int cpt = 0;
  for (int x = -SIZEOFBLOCK; x < _width * SIZEOFBLOCK + SIZEOFBLOCK; x += SIZEOFBLOCK)
  {
    this->_box[cpt] = this->_scene->addPixmap(*this->spriteTree);
    this->_box[cpt]->setPos(x, -SIZEOFBLOCK);
    cpt++;
  }
  for (int y = 0; y < _height * SIZEOFBLOCK + SIZEOFBLOCK; y += SIZEOFBLOCK)
  {
    this->_box[cpt] = this->_scene->addPixmap(*this->spriteTree);
    this->_box[cpt]->setPos(-SIZEOFBLOCK, y);
    cpt++;
  }
  for (int x = 0; x < _width * SIZEOFBLOCK + SIZEOFBLOCK; x += SIZEOFBLOCK)
  {
    this->_box[cpt] = this->_scene->addPixmap(*this->spriteTree);
    this->_box[cpt]->setPos(x, (_height) * SIZEOFBLOCK);
    cpt++;
  }
  for (int y = 0; y < _height * SIZEOFBLOCK; y += SIZEOFBLOCK)
  {
    this->_box[cpt] = this->_scene->addPixmap(*this->spriteTree);
    this->_box[cpt]->setPos(_width * SIZEOFBLOCK, y);
    cpt++;
  }
}


void Graph::Map::MapBlocks::initSprites(void)
{
  this->spriteTree = new QPixmap("./media/tree.png");
  this->spriteGrass = new QPixmap("./media/grass.png");
  for (int i = 1; i <= 7; i++)
    this->spriteRessources[i - 1] = new QPixmap(std::string("./media/" + std::to_string(i) + ".png").c_str());
  for (int i = 0; i < 8; i++)
  {
    this->spriteIncant[i] = this->getSprites(10, std::string("./media/anim/case-incant-" + std::to_string(i) + ".png"));
  }
  this->spriteIncantOK = this->getSprites(30, std::string("./media/anim/level-up.png"));
  this->spriteIncantKO = this->getSprites(5, std::string("./media/anim/incant-fail.png"));

}


QList<QPixmap> Graph::Map::MapBlocks::getSprites(int nbSprite, std::string image)
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

Graph::Map::MapBlocks::~MapBlocks()
{
  for (auto & item : this->_map)
  {
    for (auto & it : item.second._spriteRes)
    {
      if (it.second)
	delete it.second;
    }
    delete item.second.imgGraph;
  }
  delete this->spriteGrass;
  delete this->spriteTree;
  for (auto & item : this->spriteRessources)
    delete item;
}

int Graph::Map::MapBlocks::getWidth() const
{
  return _width;
}

int Graph::Map::MapBlocks::getHeight() const
{
  return _height;
}

void Graph::Map::MapBlocks::placeRessources(const int x, const int y, const int *res)
{
  t_aMapBlock		*tmp;
  QGraphicsPixmapItem	*tmpSprite;

  tmp = &this->_map[y * this->_width + x];
  for (int i = 0 ; i < 7; i++)
  {
    if (tmp->_spriteRes[i])
    {
      this->_scene->removeItem(tmp->_spriteRes[i]);
    }
    tmp->_spriteRes[i] = NULL;
  }
  for (int i = 0; i < 7; i++)
  {
    for (int nbRes = 0; nbRes < res[i]; nbRes++)
    {
      if (!tmp->_spriteRes[i])
      {
	tmpSprite = this->_scene->addPixmap(*this->spriteRessources[i]);
	tmpSprite->setPos(tmp->imgGraph->pos().x() + (20 * (i % 3)), tmp->imgGraph->pos().y() + (20 * (i / 3)));
	tmpSprite->setZValue(1);
	tmp->_spriteRes[i]= tmpSprite;
      }
    }
    tmp->ressources[i] = res[i];
  }
  if (this->_blockNfo && x == this->_blockNfo->getX() && y == this->_blockNfo->getY())
  {
    this->rmBlockNfo();
    this->addBlockNfo(x, y);
  }
}


void Graph::Map::MapBlocks::launchIncant(const int x, const int y, const int lvl)
{
  int	pos;
  t_aMapBlock	*tmp;

  pos = (y / SIZEOFBLOCK) * this->_width + (x / SIZEOFBLOCK);
  tmp = &this->_map[pos];
  if (tmp->anim && tmp->anim->getIsEnd() == true)
    {
      tmp->anim->ending();
      delete tmp->anim;
      tmp->anim = NULL;
    }
  if (lvl > 7)
  {
    std::cerr << "Bas number of level" << std::endl;
    return;
  }
  tmp->anim = new AnimatedLabel(300000 / this->_timeUnit, 5000 / this->_timeUnit, 0, &this->spriteIncant[lvl], this->_scene);
  tmp->widget = this->_scene->addWidget(tmp->anim);
  tmp->anim->setAnimPos(x * SIZEOFBLOCK, y * SIZEOFBLOCK);
}

void Graph::Map::MapBlocks::incantKO(const int x, const int y)
{
  int	pos;
  t_aMapBlock	*tmp;

  pos = (y / SIZEOFBLOCK) * this->_width + (x / SIZEOFBLOCK);
  tmp = &this->_map[pos];
  if (tmp->anim)
    delete tmp->anim;
  tmp->anim = new AnimatedLabel(1000 / this->_timeUnit, 200 / this->_timeUnit, 3, &this->spriteIncantKO, this->_scene);
  tmp->widget = this->_scene->addWidget(tmp->anim);
  tmp->anim->setAnimPos(x * SIZEOFBLOCK, y * SIZEOFBLOCK);
}

void Graph::Map::MapBlocks::incantOk(const int x, const int y)
{
  int	pos;
  t_aMapBlock	*tmp;

  pos = (y / SIZEOFBLOCK) * this->_width + (x / SIZEOFBLOCK);
  tmp = &this->_map[pos];
  if (tmp->anim)
  {
    tmp->anim->ending();
    delete tmp->anim;
  }
  tmp->anim = new AnimatedLabel(3000 / this->_timeUnit, 100 / this->_timeUnit, 3, &this->spriteIncantOK, this->_scene);
  tmp->widget = this->_scene->addWidget(tmp->anim);
  tmp->anim->setAnimPos(x * SIZEOFBLOCK, y * SIZEOFBLOCK);
}

void Graph::Map::MapBlocks::setTimeUnit(float timeUnit)
{
  if (timeUnit == 0)
    _timeUnit = 1;
  else
  _timeUnit = timeUnit;
}

void Graph::Map::MapBlocks::addBlockNfo(const int x, const int y)
{
  t_aMapBlock tmp;

  if (x < 0 || x >= this->_width || y < 0 || y >= this->_height)
    return ;
  tmp = this->_map[y * this->_width + x];
  if (this->_blockNfo)
    this->rmBlockNfo();
  this->_blockNfo = new BlockNfo(this->_scene, x, y , tmp.ressources, this->spriteRessources);
}

void Graph::Map::MapBlocks::rmBlockNfo(void)
{
  if (this->_blockNfo)
  {
    delete this->_blockNfo;
    this->_blockNfo = NULL;
  }
}

void Graph::Map::MapBlocks::changePosBlockNfo(QPointF pos)
{
  if (this->_blockNfo)
  {
    this->_blockNfo->changePos(pos);
  }
}
