#include "graph/my_qlabel_anim.hpp"

AnimatedLabel::AnimatedLabel(const int timer, const int animSpeed, const int priority, QList<QPixmap> *anim, QGraphicsScene *scene, QWidget* parent)
  :     QLabel(parent), isEnd(false), currentPixmap(0), _scene(scene)
{
  setVisible(false);
  connect(&this->timerEnd, SIGNAL(timeout()), SLOT(ending()));
  connect(&this->timerAnim, SIGNAL(timeout()), SLOT(changeImage()));
  this->timerAnim.start(animSpeed);
  this->timerEnd.start(timer);
  this->pixmaps = anim;
  this->_pixmap = scene->addPixmap(anim->at(0));
  this->_pixmap->setZValue(priority);
  changeImage();
}

void AnimatedLabel::changeImage()
{
  if (currentPixmap >= pixmaps->length())
    currentPixmap = 0;
  this->_pixmap->setPixmap(pixmaps->at(currentPixmap));
  currentPixmap++;
}

void AnimatedLabel::ending(void)
{
  this->_pixmap->setVisible(false);
  this->isEnd = true;
}

bool AnimatedLabel::getIsEnd(void) const
{
  return this->isEnd;
}

AnimatedLabel::~AnimatedLabel()
{
  this->_scene->removeItem(this->_pixmap);
}

void AnimatedLabel::setAnimPos(const int x, const int y)
{
this->_pixmap->setPos(x, y);
}
