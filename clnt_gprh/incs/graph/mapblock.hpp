#ifndef CLNT_GPRH_MAPBLOCK_HPP
#define CLNT_GPRH_MAPBLOCK_HPP

#include <QtGui/QGraphicsScene>
#include <QtGui/qpixmap.h>
#include <map>
#include "my_qlabel_anim.hpp"
#include "blocknfo.hpp"

namespace Graph
{
  namespace Map
  {
    enum : int8_t
    {
      FOOD = 0,
      LINEMATE,
      DERAUMERE,
      SIBUR,
      MENDIANE,
      PHIRAS,
      THYSTAME
    };

# ifndef	SIZEOFBLOCK
# define	SIZEOFBLOCK (64)
# endif

# ifndef	SIZEOFGUI
# define	SIZEOFGUI (100)
# endif

    typedef struct	s_aMapBlock
    {
      int		ressources[7];
      int		lvlIncant;
      AnimatedLabel	*anim;
      QGraphicsProxyWidget	*widget;
      std::map<int, QGraphicsPixmapItem *> _spriteRes;
      QGraphicsPixmapItem *imgGraph;
    }			t_aMapBlock;

    class MapBlocks
    {
    public:
      MapBlocks(QGraphicsScene *, const int &, const int &, const float);
      ~MapBlocks();

    public:
      void	placeRessources(const int, const int, const int[7]);
      void	launchIncant(const int, const int, const int);
      void	incantOk(const int, const int);
      void	incantKO(const int, const int);
      void	addBlockNfo(const int, const int);
      void	rmBlockNfo(void);
      void	changePosBlockNfo(QPointF pos);
    private:
      void	initSprites(void);
      void	createSquareBox(void);
      QList<QPixmap>	getSprites(int nbSprite, std::string img);
    private:
      std::map<int, t_aMapBlock>	_map;
      std::map<int, QGraphicsPixmapItem *> _box;
      int				_width;
      int				_height;
      QGraphicsScene			*_scene;
      float				_timeUnit;
      BlockNfo				*_blockNfo;

    private:
      QPixmap				*spriteGrass;
      QPixmap				*spriteTree;
      QPixmap				*spriteRessources[7];
      std::map<int, QList<QPixmap>>	spriteIncant;
      QList<QPixmap>			spriteIncantOK;
      QList<QPixmap>			spriteIncantKO;

    public:
      int getWidth() const;
      void setTimeUnit(float timeUnit);
      int getHeight() const;

    };
  }
}


#endif /* !CLNT_GPRH_MAPBLOCK_HPP_ */
