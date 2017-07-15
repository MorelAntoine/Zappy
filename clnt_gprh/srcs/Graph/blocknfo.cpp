
#include <graph/blocknfo.hpp>

BlockNfo::BlockNfo(QGraphicsScene *scene, const int x, const int y, const int *res,
		    QPixmap **resImp) : _scene(scene)
{
  this->_top = scene->addSimpleText(std::string("Block Info : X : " + std::to_string(x) + " Y : " + std::to_string(y)).c_str());
  _top->setZValue(11);
  this->_bottom = scene->addSimpleText(std::string("Ressources Infos :\n     Food : " + std::to_string(res[0]) +
						     "\n     Linemate : " + std::to_string(res[1]) +
						     "\n     Deraumere : " + std::to_string(res[2]) +
						     "\n     Sibur : " + std::to_string(res[3]) +
						     "\n     Mendiane : " + std::to_string(res[4]) +
						     "\n     Phiras : " + std::to_string(res[5]) +
						     "\n     Thystame : " + std::to_string(res[6])).c_str());
  _bottom->setZValue(11);
  this->mainSquare = scene->addRect(0, 0, this->_top->boundingRect().width() + 20, 220);
  if (this->mainSquare)
  {
    this->mainSquare->setZValue(10);
    this->mainSquare->setBrush(QBrush((Qt::gray)));
  }
  this->_pos.setX(x);
  this->_pos.setY(y);
  this->initResImg(resImp);
}

BlockNfo::~BlockNfo()
{
  this->_scene->removeItem(this->_top);
  this->_scene->removeItem(this->mainSquare);
  this->_scene->removeItem(this->_bottom);
  for (int i = 0; i < 7; i++)
  {
    this->_scene->removeItem(this->resImg[i]);
  }
}

void BlockNfo::changePos(const QPointF &pos)
{
  this->mainSquare->setPos(pos.x() - 600, pos.y() - 40);
  _top->setPos(pos.x() - 590, pos.y() - 30);
  _bottom->setPos(pos.x() - 590, pos.y());
  for (int i = 0; i < 7; i++)
  {
    this->resImg[i]->setPos(pos.x() - 590, pos.y() + (22 * i) + 20);
  }
}

void BlockNfo::initResImg(QPixmap **resImp)
{
  for (int i = 0; i < 7; i++)
  {
    this->resImg[i] = this->_scene->addPixmap(*resImp[i]);
    this->resImg[i]->setZValue(12);
  }
}

int BlockNfo::getY(void) const
{
  return this->_pos.y();
}

int BlockNfo::getX(void) const
{
  return this->_pos.x();
}
