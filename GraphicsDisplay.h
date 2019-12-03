#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H

#include "observer.h"
#include "player.h"
#include "window.h"

class GraphicsDisplay : public Observer {
    Xwindow window;

    public:
    ~GraphicsDisplay() {};
    GraphicsDisplay();
    void notify(Player & whoNotified) override;
};


#endif