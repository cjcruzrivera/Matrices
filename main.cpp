/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: camilojcr
 *
 * Created on 8 de febrero de 2018, 10:21 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h> 
#include <sstream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    ifstream Matriz1, Matriz2;
    
    Matriz1.open("matriz1.txt");
    Matriz2.open("matriz2.txt");
    
    cout << "La Matriz 1 es:\n\n";
    
    if(Matriz1.is_open()){
        
        int M1Filas = 0;
        int M1Colum = 0;
        
        while(!Matriz1.eof()){
            M1Filas++;
            M1Colum = 0;
            string fila;
            char * pch;
            getline(Matriz1, fila);
            cout <<" " + fila + "\n";
            pch = strtok (fila,",");
            while (pch != NULL)
            {
                M1Colum++;
                pch = strtok (NULL, " ,.-");
            }
           
        }
        
        ostringstream filasm1,columnam1; 
        filasm1 << M1Filas;
        columnam1 << M1Colum;
        cout << "Tiene " + filasm1.str() + " filas";       
        cout << "Tiene " + columnam1.str() + " columnas";

         
    }
    
    return 0;
}

