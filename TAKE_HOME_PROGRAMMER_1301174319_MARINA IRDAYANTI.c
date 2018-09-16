#include <stdio.h>
#include <conio.h>
#include <string.h>
#ifndef bool
#define bool int
#endif // bool
#ifndef true
#define true 1
#endif // true
#ifndef false
#define false 0
#endif // false

bool selesai;
selesai=false; 
int pemainpertama,besarheal;
    char aksi[100],tipe[100];
    int besarserangan;


struct{
   int hp;
}pemain;
struct{
   int hp;
}monster;

void pemaingerak(){

}
void monstergerak(){

}
main(){
    printf("HP Pemain : ");
    scanf("%d",&pemain.hp);
    printf("HP Monster: ");
    scanf("%d",&monster.hp);
    printf("Pemain Pertama : ");
    scanf("%d",&pemainpertama);
    if(pemainpertama==1){
        while(selesai==false){
            //pemain
            printf("Jenis Aksi Pemain : ");
            scanf("%s",aksi);
            if(strcmp("attack",aksi)==0){
                printf("Besar Serangan : ");
                scanf("%d",&besarserangan);
                printf("Tipe : ");
                scanf("%s",tipe);
                if(strcmp("hit",tipe)==0){
                    monster.hp=monster.hp-besarserangan;
                }else if(strcmp("critical",tipe)==0){
                    monster.hp=monster.hp-(besarserangan*2);
                }
                if(monster.hp<=0){
                    printf("%d MATI",pemain.hp);
                    selesai=true;
                }
            }else if(strcmp("heal",aksi)==0){
                printf("Besar Heal: ");
                scanf("%d",&besarheal);
                pemain.hp=pemain.hp+besarheal;
            }else if(strcmp("run",aksi)==0){
                printf("%d %d",pemain.hp,monster.hp);
                selesai=true;
            }
            //monster
            if(selesai==false){
            printf("Jenis Aksi Monster: ");
            scanf("%s",aksi);
            if(strcmp("attack",aksi)==0){
                printf("Besar Serangan : ");
                scanf("%d",&besarserangan);
                printf("Tipe : ");
                scanf("%s",tipe);
                if(strcmp("hit",tipe)==0){
                    pemain.hp=pemain.hp-besarserangan;
                }else if(strcmp("critical",tipe)==0){
                    pemain.hp=pemain.hp-(besarserangan*2);
                }
                if(pemain.hp<=0){
                    printf("MATI %d",monster.hp);
                    selesai=true;
                }
            }else if(strcmp("heal",aksi)==0){
                printf("Besar Heal : ");
                scanf("%d",&besarheal);
                monster.hp=monster.hp+besarheal;
            }else if(strcmp("run",aksi)==0){
                printf("%d %d",pemain.hp,monster.hp);
                selesai=true;
            }
            }
        }
    }else{
        while(selesai==false){
            //monster
            printf("Jenis Aksi Monster: ");
            scanf("%s",aksi);
            if(strcmp("attack",aksi)==0){
                printf("Besar Serangan : ");
                scanf("%d",&besarserangan);
                printf("Tipe : ");
                scanf("%s",tipe);
                if(strcmp("hit",tipe)==0){
                    pemain.hp=pemain.hp-besarserangan;
                }else if(strcmp("critical",tipe)==0){
                    pemain.hp=pemain.hp-(besarserangan*2);
                }
                if(pemain.hp<=0){
                    printf("MATI %d",monster.hp);
                    selesai=true;
                }
            }else if(strcmp("heal",aksi)==0){
                printf("Besar Heal : ");
                scanf("%d",&besarheal);
                monster.hp=monster.hp+besarheal;
            }else if(strcmp("run",aksi)==0){
                printf("%d %d",pemain.hp,monster.hp);
                selesai=true;
            }
            if(selesai==false){
            //pemain
            printf("Jenis Aksi Pemain : ");
            scanf("%s",aksi);
            if(strcmp("attack",aksi)==0){
                printf("Besar Serangan : ");
                scanf("%d",&besarserangan);
                printf("Tipe : ");
                scanf("%s",tipe);
                if(strcmp("hit",tipe)==0){
                    monster.hp=monster.hp-besarserangan;
                }else if(strcmp("critical",tipe)==0){
                    monster.hp=monster.hp-(besarserangan*2);
                }
                if(monster.hp<=0){
                    printf("%d MATI",pemain.hp);
                    selesai=true;
                }
            }else if(strcmp("heal",aksi)==0){
                printf("Besar Heal: ");
                scanf("%d",&besarheal);
                pemain.hp=pemain.hp+besarheal;
            }else if(strcmp("run",aksi)==0){
                printf("%d %d",pemain.hp,monster.hp);
                selesai=true;
            }
            }
        }
    }
}
