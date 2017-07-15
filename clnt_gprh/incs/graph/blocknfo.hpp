#ifndef CLNT_GPRH_BLOCKNFO_HPP
#define CLNT_GPRH_BLOCKNFO_HPP

#include <QtGui/QGraphicsScene>
#include <QtGui/QGraphicsRectItem>
#include <QtGui/QLabel>

class BlockNfo
{
public:
  BlockNfo(QGraphicsScene *scene, const int x, const int y , const int res[7],  QPixmap **resImp);
  ~BlockNfo();
  void changePos(const QPointF &);
  int		getY(void)const;
  int		getX(void)const;
private:
  void initResImg(QPixmap **resImp);
private:
  QGraphicsScene	*_scene;
  QGraphicsRectItem *mainSquare;
  QGraphicsSimpleTextItem	*_top;
  QGraphicsSimpleTextItem	*_bottom;
  QGraphicsPixmapItem		*resImg[7];
  QPoint			_pos;
};

#endif /* !CLNT_GPRH_BLOCKNFO_HPP_ */
