#ifndef CLNT_GPRH_MY_QLABEL_ANIM_HPP
#define CLNT_GPRH_MY_QLABEL_ANIM_HPP

#include <QtGui/QWidget>
#include <QtCore/QTimer>
#include <QtGui/QLabel>
#include <QtCore/QList>
#include <QtGui/QPixmap>
#include <QtGui/QGraphicsScene>
#include <QtGui/QGraphicsItem>

class AnimatedLabel : public QLabel
{
Q_OBJECT

public:
  AnimatedLabel(const int timer, const int animSpeed, const int, QList<QPixmap> *, QGraphicsScene *, QWidget* parent = 0);

public:
  bool	getIsEnd(void)const;
  void	setAnimPos(const int, const int);
  void	ending(void);
private slots:
  void changeImage();

private:
  bool		isEnd;
  int currentPixmap;
  QList<QPixmap> *pixmaps;
  QTimer timerEnd;
public:
  virtual ~AnimatedLabel();

private:
  QTimer timerAnim;
  QGraphicsPixmapItem	*_pixmap;
  QGraphicsScene	*_scene;
};


#endif /* !CLNT_GPRH_MY_QLABEL_ANIM_HPP_ */
