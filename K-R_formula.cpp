#include <iostream>

using namespace std;

double ReturnP(int n,const int M,int t[],double a[],const int V){
    if(n<0) return 0;
    else if (n==0) return 1.0;
    else{
        double P=0.0;
        for(int i=1;i<=M;i++){
            P+=a[i]*t[i]*ReturnP(n-t[i],M,t,a,V);
        }
        return P/n;
    }
}

int main()
{
    int V,M;

    cout << "wpisz M oraz V: "; //uzupelnianie informacji o M oraz V
    cin >> M >> V;;

int t[M+1]; //deklaracja ti 
double a[M+1]; //deklaracja ai

    for(int i=1;i<=M;i++){
        cout<<"Wpisz a"<<i<<" oraz t"<<i<<" : "; //uzupelnianie informacji o a1 i t1
        cin >>a[i] >> t[i];
    }

double EI[M+1]; //deklaracja tabeli blokady
double P[V+1]; //deklaracja tabeli pradopodobienstwa

double Normalizacja=0.0;
//obliczanie stałej do normalizacji
    for(int n=0;n<=V;n++){ 
        Normalizacja+=ReturnP(n,M,t,a,V);
    }
// proces obliczania prawdopodobienstwa i normalizacji
    for(int i=0;i<=V;i++){

        P[i]=ReturnP(i,M,t,a,V)/Normalizacja;
    }
//obliczanie pradopodobienstwa blokady
    for(int i=1;i<=M;i++){
        for(int n=V-t[i]+1;n<=V;n++){
            EI[i]+=P[n];
        }
    }


cout<<"Tablica P" <<endl;
    for(int i=0;i<=V;i++){
        cout<< "P["<<i<<"]= " << P[i] <<endl;
    }
cout<<"Pradopodobienstwo Blokady " <<endl;
    for(int i=1;i<=M;i++){
        cout<< "B["<<i<<"]= " << EI[i] <<endl;
    }
    return 0;
}
