#ifndef CLNT_GPRH_DISPLAY_HPP
#define CLNT_GPRH_DISPLAY_HPP

#include <QtGui/QApplication>
#include <QtGui/QWidget>
#include <QtGui/QtGui>
#include <QtGui/QPushButton>
#include <graph/graphicsscene.hpp>
#include <QtGui/QGraphicsRectItem>
#include <QtGui/QGraphicsView>
#include <QtGui/QSound>
#include "irrKlang.h"
#include "mapblock.hpp"
#include "user_manage.hpp"
#include "blocknfo.hpp"

namespace Graph
{
# ifndef	HEIGHT
# define	HEIGHT (600)
# endif

# ifndef	WIDTH
# define	WIDTH (800)
# endif

  class Display
  {
    typedef bool (Display::*MemFuncPtr)(const std::map<int, std::string> &);
  public:
    Display(char **av, int ac);
    ~Display();
    void	createArrMemPtr(void);
    bool	display(void);
    void	processLine(const std::string &);
    void	clickCenterView();

  private:
    bool	mszFunc(const std::map<int, std::string> &);
    bool	bctFunc(const std::map<int, std::string> &);
    bool	pnwFunc(const std::map<int, std::string> &);
    bool	tnaFunc(const std::map<int, std::string> &);
    bool	ppoFunc(const std::map<int, std::string> &);
    bool	plvFunc(const std::map<int, std::string> &);
    bool	pinFunc(const std::map<int, std::string> &);
    bool	pexFunc(const std::map<int, std::string> &);
    bool	pbcFunc(const std::map<int, std::string> &);
    bool	picFunc(const std::map<int, std::string> &);
    bool	pieFunc(const std::map<int, std::string> &);
    bool	pfkFunc(const std::map<int, std::string> &);
    bool	pdrFunc(const std::map<int, std::string> &);
    bool	pgtFunc(const std::map<int, std::string> &);
    bool	pdiFunc(const std::map<int, std::string> &);
    bool	enwFunc(const std::map<int, std::string> &);
    bool	ehtFunc(const std::map<int, std::string> &);
    bool	eboFunc(const std::map<int, std::string> &);
    bool	ediFunc(const std::map<int, std::string> &);
    bool	segFunc(const std::map<int, std::string> &);
    bool	sgtFunc(const std::map<int, std::string> &);
  private:
    void	epurStr(std::string &);
    std::map<int, std::string>	getArgs(const std::string &);

  private:
    QApplication				*app;
    MyGraphicsScene				*scene;
    QGraphicsView				*view;
    std::map<std::string, MemFuncPtr>		_arrPtrMemb;
    Graph::Map::MapBlocks			*_map;
    Graph::User::UsrManage			*_usrs;
    float					_timeUnit;
    irrklang::ISoundEngine*			engine;
    QPointF					_lastPos;
  };
}

#endif /* !CLNT_GPRH_DISPLAY_HPP_ */
