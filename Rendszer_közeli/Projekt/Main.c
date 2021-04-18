#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define VERSION "--version"
#define HELP "--help" 


/*  A függvény hozzon létre dinamikus memóriafoglalással 3 pixel 
    adatainak tárolására alkalmas tömböt! 
    (Képzeljük azt, hogy ez egy bmp képfájl ún. pixel array bájtsorozatát tartalmazza!)
    A  tömb  minden elemének első 5 bitpozíciója egyenletes eloszlással 
    véletlenszerűen legyen feltöltve, míg az utolsó 3 pozícióba a fenti leírás alapján  
    kódoldbitműveletek segítségével az „abc” konstans sztringet!  
    A függvény a paraméterként megadott változó memóriaterületére helyezze el a kódolt 
    kerekterek számát (3) majd térjen vissza a lefoglalt memóriaterület címével! */

char* TestArray(int *NumCh)
{
    srand(time(NULL)); 
    int S = rand() % 2;
    
    int* p = (int*) malloc(3);
    int hossz = 24;

    if (p == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    
    for (int i = 0; i < 24; i++)
    {
        p[i] = S;  
    }

    
}




int main(int argc, char *argv[]){
    char *file_name;
    
    
    // Ha 1 db parancssori argumentumot adunk meg
    if (argc==2)
    {   
        //Ha az az 1 parancssori argumentum a "--version" 
        if(strcmp(argv[1],VERSION ))
        {
            printf("Program verziószáma:    \n");
            printf("Program elkészültének dátuma:\n");
            printf("Fejlesztő neve: \n");

            return EXIT_SUCCESS;
        }
        //Ha az az 1 parancssori argumentum a "-help"
        else if(strcmp(argv[1],HELP))
        {
            printf("Tájékoztatás a felhasználónak a futtatás lehetséges opcióiról!:\n");
            printf("info\n");
            printf("info\n");

            return EXIT_SUCCESS;
        }
        //Egyéb esetben az az 1 parancssori argumentum a feldolgazando FILE neve
        else
        {
            file_name=argv[1];
            puts("file nev megvan");
        }


    }


}