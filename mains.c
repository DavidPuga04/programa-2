#include <stdio.h>
#include <math.h>
float calcularDistancia(float x1, float y1, float z1, float x2, float y2, float z2);
float calcularPerimetro(float puntos [4][3], float *L1, float *L2, float *L3, float *L4, float *L5, float *L6);
float calcularArea (float L1, float L2, float L3);
void calcularBaricentro (float puntos[4][3], float *gx, float *gy, float *gz);
void calcularAltura(float L1, float L2, float L3, float gx, float gy, float gz, float puntos[4][3], float *altura);
float calcularVolumen(float altura, float areabase);

int main(int argc, char const *argv[])
{
    float puntos [4][3]={{0,0,0},{0,0,3},{3,0,0},{1,7,1}};
    float L1, L2, L3, L4, L5 , L6, gx, gy, gz, altura;
    
    float perimetro=calcularPerimetro(puntos, &L1,&L2,&L3,&L4,&L5,&L6);
    float areabase= calcularArea(L1,L2,L3);
    float area1= calcularArea(L1,L4,L5);
    float area2= calcularArea(L2,L4,L6);
    float area3= calcularArea(L3,L5,L6);
    calcularAltura(L1, L2, L3, gx, gy, gz, puntos, &altura);
    float volumen= calcularVolumen(altura, areabase);
    printf("El perimetro es: %.2f \n", perimetro);
    float areatotal=areabase+area1+area2+area3;
    printf("El area del triangulo es: %.2f\n", areatotal);
    printf("El volumen es: %.2f", volumen);
    return 0;
}

float calcularDistancia(float x1, float y1, float z1, float x2, float y2, float z2){
    float dist=sqrt(pow(x1-x2,2)+pow(y1-y2,2)+pow(z1-z2,2));
    return dist;
}
float calcularPerimetro(float puntos [4][3], float *L1, float *L2, float *L3, float *L4, float *L5, float *L6){
    *L1=calcularDistancia (puntos[0][0], puntos[0][1], puntos[0][2], puntos[1][0], puntos[1][1], puntos[1][2]);
    *L2=calcularDistancia (puntos[0][0], puntos[0][1], puntos[0][2], puntos[2][0], puntos[2][1], puntos[2][2]);
    *L3=calcularDistancia (puntos[1][0], puntos[1][1], puntos[1][2], puntos[2][0], puntos[2][1], puntos[2][2]);

    *L4=calcularDistancia (puntos[0][0], puntos[0][1], puntos[0][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    *L5=calcularDistancia (puntos[1][0], puntos[1][1], puntos[1][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    *L6=calcularDistancia (puntos[2][0], puntos[2][1], puntos[2][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    float perimetro= *L1 + *L2 + *L3 +*L4+*L5+*L6;
    return perimetro;
}
float calcularArea (float L1, float L2, float L3){
    float s=(L1+L2+L3)/2;
    float area= sqrt(s*(s-L1)*(s-L2)*(s-L3));
    return area;
}
void calcularBaricentro (float puntos[4][3], float *gx, float *gy, float *gz){
    *gx=(puntos[0][0]+puntos[1][0]+puntos[2][0]+puntos[3][0])/3;
    *gy=(puntos[0][1]+puntos[1][1]+puntos[2][1]+puntos[3][1])/3;
    *gz=(puntos[0][2]+puntos[1][2]+puntos[2][2]+puntos[3][2])/3;
}
void calcularAltura(float L1, float L2, float L3, float gx, float gy, float gz, float puntos[4][3], float *altura){
    *altura=calcularDistancia(gx, gy, gz, puntos[3][0], puntos[3][1], puntos[3][2]);
}

float calcularVolumen(float altura, float areabase){

    float volumen= (areabase*altura)/3;
    return volumen;
}