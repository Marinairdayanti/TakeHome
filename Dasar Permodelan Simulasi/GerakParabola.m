clear all;
t=0; tmaks=4.39; h=0.025; n=(tmaks-t)/h;
g=9.8;m=0.1; v = 30; tt=45/180*pi; x=0; y=0; vx=v*cos(tt); vy=v*sin(tt);
ax=0; ay=-g; T=1/2*m*v^2; V=m*g*y;
for i=1:n
    xp(i)=x; yp(i)=y; tp(i)=T; vp(i)=V; ep(i)=T+V; ttp(i)=t;
    x=x+h*vx;
    y=y+h*vy;
    vx=vx+h*ax;
    vy=vy+h*ay;
    ax=0; ay=-g;
    v=sqrt(vx^2+vy^2); T=1/2*m*v^2; V=m*g*y; 
    t=t+h;
end;
subplot(2,2,1);
plot(xp,yp); grid on; title('Gerak Parabola');
