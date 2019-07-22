/* Ejercicio5
# Resuelva el siguiente sistema acoplado de ecuaciones diferenciales 
# dx/dt = sigma * (y - x)
# dy/dt = rho * x - y -x*z
# dz/dt = -beta * z + x * y
# con sigma = 10, beta=2.67, rho=28.0,
# condiciones iniciales t=0, x=0.5, y=-1.0, z=1.0, hasta t=5.0.
# Prepare dos graficas con la solucion: de x vs y (xy.png), x vs. z (xz.png)*/ 

#include <iostream>
#include<fstream>

using namespace std;

double dxdt(double t,double x,double y, double z);
double dydt(double t,double x,double y, double z);
double dzdt(double t,double x,double y, double z);

void RK4(double t0, double tf, double xini, double yini, double zini, int npuntos, double delta , string filename);

int main(){
    
    double tini=0.0;
    double tfinal=5.0;
    double x0=0.5;
    double y0=-1.0;
    double z0=1.0;
    RK4(tini, tfinal,x0,y0,z0, 1000, 0.01, "ecuaciones.txt");
    
    return 0;
}

double dxdt(double t,double x,double y, double z){
    double sigma=10.0;
    return sigma*(y-x);
}

double dydt(double t,double x,double y, double z){
    double rho= 28.0;
    return (rho*x) - y - (x*z);
}

double dzdt(double t,double x,double y, double z){
    double beta=2.67;
    return (-beta * z) + (x * y);
}


void RK4(double t0, double tf, double xini, double yini, double zini, int npuntos, double delta , string filename){
 
    ofstream outfile;
    outfile.open(filename);
    
    double dt = (tf-t0)/(npuntos-1);
    
    double t[npuntos];
    t[0]=t0;
   
    double x[npuntos];
    x[0]=xini;
    
    double y[npuntos];
    y[0]=yini;
    
    double z[npuntos];
    z[0]=zini;
    
    double k1x,k2x,k3x,k4x;
    double k1y,k2y,k3y,k4y;
    double k1z,k2z,k3z,k4z;
    
    double promediox, promedioy, promedioz;
    
    for(int i=1; i<npuntos; i++){
        t[i]= t[i-1]+dt;
    }
    
    
    for (int i=1; i<npuntos; i++){
        
        k1x= delta*dxdt(t[i-1],x[i-1],y[i-1],z[i-1]);
        k1y= delta*dydt(t[i-1],x[i-1],y[i-1],z[i-1]);
        k1z= delta*dzdt(t[i-1],x[i-1],y[i-1],z[i-1]);


        k2x=delta*dxdt(t[i-1]+(0.5*delta),x[i-1]+(0.5*k1x),y[i-1]+(0.5*k1y),z[i-1]+(0.5*k1z));
        k2y=delta*dydt(t[i-1]+(0.5*delta),x[i-1]+(0.5*k1x),y[i-1]+(0.5*k1y),z[i-1]+(0.5*k1z));
        k2z=delta*dzdt(t[i-1]+(0.5*delta),x[i-1]+(0.5*k1x),y[i-1]+(0.5*k1y),z[i-1]+(0.5*k1z));
        
        k3x=delta*dxdt(t[i-1]+(0.5*delta),x[i-1]+(0.5*k2x),y[i-1]+(0.5*k2y),z[i-1]+(0.5*k2z));
        k3y=delta*dydt(t[i-1]+(0.5*delta),x[i-1]+(0.5*k2x),y[i-1]+(0.5*k2y),z[i-1]+(0.5*k2z));
        k3z=delta*dzdt(t[i-1]+(0.5*delta),x[i-1]+(0.5*k2x),y[i-1]+(0.5*k2y),z[i-1]+(0.5*k2z));
        
        k4x=delta*dxdt(t[i-1]+delta,x[i-1]+k3x,y[i-1]+k3y,z[i-1]+k3z);
        k4y=delta*dydt(t[i-1]+delta,x[i-1]+k3x,y[i-1]+k3y,z[i-1]+k3z);
        k4z=delta*dzdt(t[i-1]+delta,x[i-1]+k3x,y[i-1]+k3y,z[i-1]+k3z);
        
        promediox=(1.0/6.0)*(k1x+(2.0*k2x)+(2.0*k3x)+k4x);
        promedioy=(1.0/6.0)*(k1y+(2.0*k2y)+(2.0*k3y)+k4y);
        promedioz=(1.0/6.0)*(k1z+(2.0*k2z)+(2.0*k3z)+k4z);
        
        x[i]=x[i-1] + promediox;
        y[i]=y[i-1] + promedioy;
        z[i]= z[i-1] + promedioz;
        
    }
    
    for(int i=0; i<npuntos; i++){
        outfile << t[i] << "  " << x[i] << "  " << y[i] << "  " << z[i] << endl;
    }
    
   outfile.close();
    
}