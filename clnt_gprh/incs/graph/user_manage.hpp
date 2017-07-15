#ifndef CLNT_GPRH_USER_MANAGE_HPP_
#define CLNT_GPRH_USER_MANAGE_HPP_

#include <QtGui/QGraphicsScene>
#include <QtGui/QGraphicsItem>
#include <QtGui/QMessageBox>
#include <map>
#include <iostream>
#include "my_qlabel_anim.hpp"

namespace Graph
{
  namespace User
  {
    enum		Orientation : int
    {
      NORD = 1,
      EST,
      SUD,
      OUEST
    };

    enum		Animation
    {
      BROADCAST = 0,
      LEVELUP
    };

# ifndef	SIZEOFBLOCK
# define	SIZEOFBLOCK (64)
# endif

# ifndef	USRMARGINH
# define	USRMARGINH (10)
# endif

# ifndef	USRMARGINW
# define	USRMARGINW (15)
# endif

    typedef struct	s_User
    {
      int			id;
      int			x;
      int			y;
      int			lvl;
      int			orient;
      bool			isDead;
      int			teamNb;
      std::string		teamName;
      QGraphicsPixmapItem	*spritePlayer;
      AnimatedLabel		*anim;
      QGraphicsProxyWidget	*widget;
      int			inventory[7];

    }			t_User;

    typedef	t_User t_Egg;

    class UsrManage
    {
    public:
      UsrManage(QGraphicsScene *, const float);
      virtual ~UsrManage();

    public:
      void		addPlayer(const int, const int, const int, const int, const int, const std::string &);
      void		movePlayer(const int, const int, const int, const int);
      void		addTeam(const std::string &);
      void		changePlayerTeam(const int, const int);
      void		setPlayerInvt(const int, const int, const int, const int [7]);
      void		addBroadcast(const int);
      void		startIncantBroadcast(const std::map<int, std::string> &);
      void		addRessource(const int, const int);
      void		removeRessource(const int, const int);
      void		killPlayer(const int);
      void		dropEgg(const int, const int, const int, const int);
      void		killEgg(const int);
      void		bornEgg(const int);
      void		printWinner(const std::string &);
    private:
      void		initSprite(void);
      void		checkUser(std::list<t_User> &);
      t_User		initEntity(const int, const int, const int, const int, const int, const std::string &, bool);
      QList<QPixmap>	getSprites(int nbSprite, std::string img);

    private:
      std::map<int, std::map<int, QList<QPixmap>>>	spritePlayer;
      std::map<int, QList<QPixmap>>			spriteAnimation;
      QList<QPixmap>					spriteEgg;
      QList<QPixmap>					spriteEggOK;
      QList<QPixmap>					spriteEggKO;
      QList<QPixmap>					spriteAddRes;
      QList<QPixmap>					spriteDelRes;
      QList<QPixmap>					spriteDeath;

    private:
      QGraphicsScene			*_scene;
      std::list<std::string>		_teams;
      std::list<t_User>			_usrs;
      std::list<t_Egg>			_eggs;
      bool				haveWinner;
      float				_timeUnit;

    public:
      bool isHaveWinner() const;
      void setTimeUnit(const float timeUnit);

    private:

    };
  }

}

#endif /* !CLNT_GPRH_USER_MANAGE_HPP_ */
