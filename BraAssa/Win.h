#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <windows.h>
#include "SystemMechanisms.h"
#include "Animation.h"



using namespace std;

class Win
{
private:
    /*int weight = 1000;
    int height = 1000;*/
   
    int WHArrMonitor[2] = { 800,600 };
    sf::RenderWindow window;
    typedef const wchar_t* LPCWSTR;
    LPCWSTR somefunc = L"������ ������";
    LPCWSTR Title = L"������";
    string SeattleSans = "data\\ttf\\Seattle_Sans.ttf";
    /*string SeattleSans = "Seattle_Sans.ttf";*/

    bool inc = 0;

    sf::Font font;
    sf::Text text;

    
public:
    
   
    Win() :window(sf::VideoMode(WHArrMonitor[0], WHArrMonitor[1]), "My Window") {
        /*sf::VideoMode(WHArrMonitor[0], WHArrMonitor[1]), "My Window";*/
        if (!font.loadFromFile(SeattleSans))
        {
            MessageBox(GetActiveWindow(), somefunc, Title, MB_ICONERROR);
        }
        
        text.setFont(font); // ��������� ������
        text.setString("Hello, World!");
        // ��������� ������
        text.setCharacterSize(24);
        text.setPosition(100, 200);
        // ��������� ������� ������
        text.setFillColor(sf::Color::White); // ��������� ����� ������
        // ������������ ������ � ������ ����
        text.setPosition((WHArrMonitor[0] - text.getGlobalBounds().width) / 2, (WHArrMonitor[0] - text.getGlobalBounds().height) / 2);
    }
   /* Animation* AnimationPtr;*/
    sf::RenderWindow& GetWindow()
    {
        return window; // ���������� ������ ���� window
    }
    void DrawText()
    {
        window.draw(text); // ��������� ������ � ����
    }
    bool incR() {
        return inc = 1;
    }


    int* WHArrMonitorGet(string OS)
    {
        // Allocate space for 2 integers

        if (OS == "WinOS") {
            WHArrMonitor[0] = GetSystemMetrics(0);  // Set width
            WHArrMonitor[1] = GetSystemMetrics(1);  // Set height
        }
        return WHArrMonitor;
    } 
    //Animation* AnimationGetP(Animation& anim) {
    //    return/* AnimationPtr =*/ &anim;
    //}



    

    
  
};


