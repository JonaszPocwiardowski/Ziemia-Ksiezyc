#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define G 6.67408e-11

struct ksiezyc
{
    float x;
    float y;
    float f0x;
    float f0y;
    float m;
    float fx;
    float fy;
    float vx;
    float vy;
    float Ek;
};

struct ziemia
{
    float x;
    float y;
    float m;
    float f0x;
    float f0y;
    float fx;
    float fy;
    float vx;
    float vy;
    float Ek;
};


struct dane
{
    float Ep;
    float Ec;
    float d;
};


void odleglosc(struct dane *D, struct ksiezyc *K, struct ziemia *Z);
void sila_zero(struct dane *D, struct ziemia *Z, struct ksiezyc *K);
void sila(struct dane *D, struct ziemia *Z, struct ksiezyc *K);
void Ek(struct ksiezyc *K, struct ziemia *Z);
void Ep(struct dane *D, struct ksiezyc *K, struct ziemia *Z);
void Ec(struct dane *D, struct ksiezyc *K, struct ziemia *Z);

int main() {
	
	FILE *plik=fopen("wyniki.txt","w");
    FILE *config=fopen("config.txt","r");

    if(!plik || !config)
	{
    	perror("nie mozna otworzyc pliku\n");
    	return 13;
	}


    float min, krok, time;
    fscanf(config, "Czas trwania symulacji(w dniach):%f\n", &time);
    fscanf(config, "Krok czasowy(w dniach):%f\n", &krok);
    fscanf(config, "O ile ma maleć masa w każdym kroku:%e\n", &min);
    

    struct ziemia Z;
    struct ksiezyc K;
    struct dane D;
    K.m=7.347673e22;
    Z.m=5.97219e24;
    Z.x=0;
    Z.y=0;
    K.x=405696e3;
    K.y=0;
    K.f0x=0;
    K.f0y=0;
    Z.f0x=0;
    Z.f0y=0;
    
    K.vx=0;
    K.vy=0.968e3;
    Z.vx=0;
    Z.vy=0;
  

	float t = 0 ;
	float dt = krok * 3600 * 24;
	float tN = time *  3600 * 24;

    odleglosc(&D, &K, &Z);
    Ek(&K, &Z);
    Ep(&D, &K, &Z);
    Ec(&D, &K, &Z);
	
	fprintf(plik,"# t   Zx  Zy  Kx  Ky  Zvx Zvy Kvx Kvy ZEk KEk Ep  Ec\n"); 
	fprintf(plik,"%f  %e  %e  %e  %e  %e  %e  %e  %e  %e  %e  %e  %e\n", t, Z.x, Z.y, K.x, K.y, Z.vx, Z.vy, K.vx, K.vy, Z.Ek, K.Ek, D.Ep, D.Ec);
	
	
	while(t < tN && Z.m>0)
	{
		t += dt;
        
        Z.m -=min;
		
        odleglosc(&D, &K, &Z);
		sila_zero(&D, &Z, &K);
		
		
			K.x = K.x + K.vx * dt + 0.5f * K.f0x/K.m * dt*dt; 
            K.y = K.y + K.vy * dt + 0.5f * K.f0y/K.m * dt*dt;
            Z.x = Z.x + Z.vx * dt + 0.5f * Z.f0x/Z.m * dt*dt;
            Z.y = Z.y + Z.vy * dt + 0.5f * Z.f0y/Z.m * dt*dt;
		

		odleglosc(&D, &K, &Z);
		sila(&D, &Z, &K);
		
		
		
			K.vx = K.vx + 0.5f * ( K.f0x + K.fx )/K.m * dt;
            K.vy = K.vy + 0.5f * ( K.f0y + K.fy )/K.m * dt;
            Z.vx = Z.vx + 0.5f * ( Z.f0x + Z.fx )/Z.m * dt;
            Z.vy = Z.vy + 0.5f * ( Z.f0y + Z.fy )/Z.m * dt;

            odleglosc(&D, &K, &Z);
            Ek(&K, &Z);
            Ep(&D, &K, &Z);
            Ec(&D, &K, &Z);

		
		
		fprintf(plik,"%f  %e  %e  %e  %e  %e  %e  %e  %e  %e  %e  %e  %e\n", t, Z.x, Z.y, K.x, K.y, Z.vx, Z.vy, K.vx, K.vy, Z.Ek, K.Ek, D.Ep, D.Ec);
	}
	
	fclose(plik);
	
	return 0;
}

void odleglosc(struct dane *D, struct ksiezyc *K, struct ziemia *Z)
{
	float dx, dy;
    dx = K->x-Z->x;
    dy = K->y-Z->y;
    D->d=sqrt(dx*dx+dy*dy);//m
}

void sila_zero(struct dane *D, struct ziemia *Z, struct ksiezyc *K)
{
	int i;
	float Ftmp = (-G * K->m * Z->m) / pow(D->d  ,3);
	
		K->f0x = Ftmp * (K->x - Z->x);
        K->f0y = Ftmp * (K->y - Z->y);
        Z->f0x = Ftmp * (Z->x - K->x);
        Z->f0y = Ftmp * (Z->y - K->y);
}

void sila(struct dane *D, struct ziemia *Z, struct ksiezyc *K)
{
	float F = (-G * K->m * Z->m) / pow( D->d ,3);
	
		K->fx = F * (K->x - Z->x);
        K->fy = F * (K->y - Z->y);
        Z->fx = F * (Z->x - K->x);
        Z->fy = F * (Z->y - K->y);
}

void Ek(struct ksiezyc *K, struct ziemia *Z)
{
    K->Ek = K->m*(pow(K->vx,2)+pow(K->vy,2))*0.5;
    Z->Ek = Z->m*(pow(Z->vx,2)+pow(Z->vy,2))*0.5;
}

void Ep(struct dane *D, struct ksiezyc *K, struct ziemia *Z)
{
    D->Ep = (-G*Z->m*K->m)/(D->d);
}

void Ec(struct dane *D, struct ksiezyc *K, struct ziemia *Z)
{
    D->Ec=K->Ek+Z->Ek+D->Ep;
}