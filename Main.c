#include <stdio.h>
#include <math.h>

float calculardiatancia(float x1, float y1, float x2, float y2);
float calcularperimetro(float puntos[3][2], float *a, float *b, float *c);
float calculararea(float a, float b, float c);

int main () {

    float puntos [3][2]={{0,0},{0,3},{3,0}};
    float a, b, c;
    
    float perimetro= calcularperimetro(puntos,&a,&b,&c);
    
    printf("El perimetro del triangulo es: %.2f \n", perimetro);
    float area= calculararea(a,b,c);
    printf("El area del triangulo es:%.2f", area);
    return 0;
}

float calculardiatancia(float x1, float y1, float x2, float y2){
    float dist=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
    return dist;

}

float calcularperimetro(float puntos[3][2], float *a, float *b, float *c){
    *a = calculardiatancia(puntos[0][0], puntos[0][1], puntos[1][0], puntos[1][1]);
    *b = calculardiatancia(puntos[0][0], puntos[0][1], puntos[2][0], puntos[2][1]);
    *c = calculardiatancia(puntos[2][0], puntos[2][1], puntos[1][0], puntos[1][1]);
    float perimetro=*a+*b+*c;
    return perimetro;

}

float calculararea(float a, float b, float c){
    float s = (a+b+c)/2;
    float area=sqrt(s*(s-a)*(s-b)*(s-c)); 
    return area;
    

}