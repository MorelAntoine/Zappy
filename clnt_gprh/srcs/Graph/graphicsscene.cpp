#include <graph/graphicsscene.hpp>

MyGraphicsScene::MyGraphicsScene() : QGraphicsScene(), _pos(-1, -1)
{

}

void MyGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
  QGraphicsScene::mouseMoveEvent(mouseEvent);
}

void MyGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
  if (event->button() == Qt::LeftButton)
  {
    this->_pos = event->scenePos();
  }
  else
  {
    this->_pos.setX(-1);
    this->_pos.setY(-1);
  }
}

void MyGraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
  QGraphicsScene::mouseReleaseEvent(event);
}

const QPointF &MyGraphicsScene::getPos() const
{
  return _pos;
}

