#include <SFML/Graphics.hpp>
#include "Win.h"
#include <chrono>
#include <thread>
#include"SystemMechanisms.h"
#include "Animation.h"

using namespace sf;
using namespace std;

int main() {
    
    SystemMechanisms* SystemMech = new SystemMechanisms();
    SystemMech->PCanalysis();
    
    Win* win = new Win();
    Animation* animation = new Animation(win);
  
    RenderWindow& window= win->GetWindow();
    window.setSize(sf::Vector2u(SystemMech->WHArrMonitor[0], SystemMech->WHArrMonitor[1]));
    window.setFramerateLimit(SystemMech->monitorFrequency);
    /*window.setVerticalSyncEnabled(true);*/
    
    

   
    
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            
        }
        
        window.clear();
      
        
        win->GetWindow().clear();
        // отрисовка других объектов, если необходимо
        win->DrawText(); // отрисовка текста
        win->GetWindow().display();
        
      
       
    }

    return 0;

}


