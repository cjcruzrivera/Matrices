/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdio>
#include <cstdlib>


/* 
 * File:   main.cpp
 * Author: camilojcr
 *
 * Created on 8 de febrero de 2018, 10:21 PM
 */
//


#include <stdio.h>
#include <iostream>
#include <string.h> 
#include <stdlib.h> 

using namespace std;

/*
 * 
 */

int m1[100][100], m2[100][100], f1, c1, f2, c2;

void leerMatriz(string ruta, int m){
    
    FILE *archivo;
    archivo = fopen(ruta.c_str(),"r");
    int i,j;
    
    if(archivo == NULL){
        exit(EXIT_FAILURE);
    }
    
    char aux[100], *token;
    i = 0;
    
    while(!feof(archivo)){
        fscanf(archivo,"%s",aux);
        token = strtok(aux, ",");
        j = 0;
        while(token != NULL){
            cout << token << " ";
            if(m == 1){
                m1[i][j] = atoi(token);
            }else if(m == 2){
                m2[i][j] = atoi(token);
            }
            token = strtok(NULL, ",");
            j++;
        }
        cout << endl;
        i++;
    }
    if(m == 1){
        f1 = i;
        c1 = j;
    }else if(m == 2){
        f2 = i;
        c2 = j;
    }
    
}

void traspuesta(int matriz){
    
    int filas, columnas;
    
    if(matriz == 1){
        filas = c1;
        columnas = f1;
    }else if(matriz == 2){
        filas = c2;
        columnas = f2;
    }
    
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            if(matriz == 1){
                cout << m1[j][i] << " ";
            }else if(matriz == 2){
                cout << m2[j][i] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void producto(){
    
    if(c1 != f2){
        cout << "Producto no posible" << endl;
    }else{
        
       
       for (int i = 0; i < f1; i++) {
           for(int j = 0; j < c2; j++){
               int value = 0;
               for(int k = 0; k < c1; k++){
                    value += m1[i][k] * m2 [k][j]; 
               }
               cout << value << " ";
              
           }
           cout << endl;
        }

        
    }
    
}

int main(int argc, char** argv) {
    
    cout << "*****************************" << endl;
    cout << "**** SISTEMA DE MATRICES ****" << endl;
    cout << "*****************************" << endl << endl;
    
    cout << "El siguiente sistema permite la lectura de dos matrices (de tamaño maximo 100 x 100)"<< endl <<"El calculo de sus traspuesta y de su producto" << endl;
    
    int respuesta = 0;
    
    do{
        if(respuesta != 1 and respuesta != 2 and respuesta != 0){
            cout << "RESPUESTA NO VALIDA" << endl;
        }
        cout << "Ingrese 1 para un ejemplo o 2 para nuevas matrices" << endl;
        cin >> respuesta;
    }while(respuesta != 1 and respuesta != 2);

    if(respuesta == 1){
        cout << "La matriz 1 es: " << endl;
        leerMatriz("matriz1.txt", 1);
        cout << "La matriz 2 es: " << endl;
        leerMatriz("matriz2.txt", 2);
        cout << "La Traspuesta de la matriz 1 es: "<< endl;
        traspuesta(1);
        cout << "La Traspuesta de la matriz 2 es: "<< endl;
        traspuesta(2);
        cout << "Y el producto de estas matrices es: " << endl;
        producto();
        
    }else if(respuesta == 2){
        string matriz1; 
        string matriz2;
        cout << "Ingrese el nombre del archivo donde se encuentra la matriz 1: " << endl;
        cin >> matriz1;
        cout << endl << "Ingrese el nombre del archivo donde se encuentra la matriz 2: " << endl;
        cin >> matriz2;
        
        cout << "La matriz 1 es: " << endl;
        leerMatriz(matriz1, 1);
        cout << "La matriz 2 es: " << endl;
        leerMatriz(matriz2, 2);
        cout << "La Traspuesta de la matriz 1 es: "<< endl;
        traspuesta(1);
        cout << "La Traspuesta de la matriz 2 es: "<< endl;
        traspuesta(2);
        cout << "Y el producto de estas matrices es: " << endl;
        producto();
        
    }
            
    return 0;
}

