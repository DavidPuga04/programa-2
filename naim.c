#include <stdio.h>
#include <math.h>

float calculardiatancia(float x1, float y1, float z1, float x2, float y2, float z2);
float calcularperimetro(float puntos[4][3], float *L1, float *L2, float *L3, float *L4, float *L5, float *L6);
float calculararea(float L1, float L2, float L3);
float calcularbaricentro(float puntos[4][3], float *gx, float *gy, float *gz);
void calcularaltura(float [4][3], float *gx, float *gy, float *gz, float *altura, float L1, float l2, float L3);
float calcularvolumen(float puntos[4][3]);

int main (int argc, char *argv[]) {

    float puntos[4][3] = {{0, 0, 0}, {0, 0, 3}, {3, 0, 0}, {1, 7, 1}};
    float per, L1, L2, L3, L4, L5, L6, vol;
    float perimetro= calcularperimetro(puntos, &L1, &L2, &L3, &L4, &L5, &L6);
    float areabase = calculararea(L1, L2, L3);
    float area1 = calculararea(L2, L4, L5);
    float area2 = calculararea(L1, L5, L6);
    float area3 = calculararea(L5, L6, L1);
    printf ("El perimetro del triangulo es: %.2f", perimetro);

    return 0;
}

float calculardiatancia(float x1, float y1, float z1, float x2, float y2, float z2){
    float dist= sqrt(pow(x1-x2,2)+pow(y1-y2,2)+pow(z1-z2,2));
    return dist;
}

float calcularperimetro(float puntos[4][3], float *L1, float *L2, float *L3, float *L4, float *L5, float *L6){
    *L1 = calculardiatancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[1][0], puntos[1][1], puntos[1][2]);
    *L2 = calculardiatancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[2][0], puntos[2][1], puntos[2][2]);
    *L3 = calculardiatancia(puntos[1][0], puntos[1][1], puntos[1][2], puntos[2][0], puntos[2][1], puntos[2][2]);
    *L4 = calculardiatancia(puntos[2][0], puntos[2][1], puntos[2][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    *L5 = calculardiatancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    *L6 = calculardiatancia(puntos[1][0], puntos[1][1], puntos[1][2], puntos[3][0], puntos[3][1], puntos[3][2]);

    float per= *L1+*L2+*L3+*L4+*L5+*L6;
    return per;
}

float calculararea(float L1, float L2, float L3){
    float smp = (L1+L2+L3)/2;
    float area = sqrt(smp*(smp-L1)*(smp-L2)*(smp-L3));
    return area;
}

float calcularbaricentro(float puntos[4][3], float *gx, float *gy, float *gz){
    *gx = (puntos[0][0]+puntos[1][0]+puntos[2][0]+puntos[3][0])/3;
    *gy = (puntos[0][1]+puntos[1][1]+puntos[2][1]+puntos[3][1])/3;
    *gz = (puntos[0][2]+puntos[1][2]+puntos[2][2]+puntos[3][2])/3;
}

void calcularaltura(float puntos[4][3], float gx, float gy, float gz, float *altura, float L1, float l2, float L3){
    *altura= calculardiatancia(gx, gy, gz, puntos[3][0], puntos[3][1], puntos[3][2])

}


float calcularvolumen(float L1, float L2, float L3, float altura){
    float areabase = calculararea(L1, L2, L3);
    float volumen=(areabase*altura)/3;
    return volumen;

}
