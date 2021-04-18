#include<stdio.h>
#include<stdlib.h>


struct BITMAP
{
    char name[2];
    unsigned int size;
    int garbage;
    unsigned int image_offset;
   
};

struct DIB
{
    unsigned int dib_size;
    unsigned int width;
    unsigned int height;
    unsigned short int colorplans;
    unsigned short int bitsperpixel;
    unsigned int compression;
    unsigned int image_size;
};

struct RGB
{
    unsigned char blue;
    unsigned char green;
    unsigned char red;

};

struct Image
{
    int height;
    int width;
    struct RGB **rgb;
};

struct Image readImage(FILE *fp, int height, int width){
    
    struct Image pic;
    pic.rgb = (struct RGB**)malloc(height*sizeof(void*));
    pic.height=height;
    pic.width=width;

    for(int i=pic.height-1;i>=0;i--){
        pic.rgb[i]= (struct RGB*)malloc(pic.width*sizeof(struct RGB));
        fread(pic.rgb[i],width,sizeof(struct RGB),fp);
    }

    return pic;
}

void freeImage(struct Image pic){
    int i;
    for(int i=pic.height-1;i>=0;i--) 
    {
        free (pic.rgb[i]); 
    }
    free(pic.rgb);
}


void RGBimageToChar(struct Image pic)
{
    int i,j;
    unsigned char result;

    for (i=0;i<pic.height;i++)
    {
        for (j = 0; j < pic.width; j++)
        {   //bbb ggg rr
            unsigned char red= (pic.rgb[i][j].red & 3) << 6;
            unsigned char green= (pic.rgb[i][j].green & 7) << 3;
            unsigned char blue= (pic.rgb[i][j].blue & 7) ;
            result= red|green|blue;
            
            //printf("red: %d\ngreen: %d\nblue: %d\nresult: %d --> %c\n-----------\n",red,green,blue,result,result);
            
            //result= red+green+blue;
            printf("%c",result);
        }
        
    }
}


void openbmpfile(){
    FILE *fp = fopen("proc2.bmp", "rb" );
    
    if (fp == NULL){
        fprintf(stderr, "A file nem található");
        fclose(fp);
        return ;
    }

    struct BITMAP header;
    struct DIB dib;
  

    fread(header.name,2,1,fp);
    fread(&header.size,3*sizeof(int),1,fp);

    //fread(&header,sizeof(struct header),1,fp);

    printf("Az első két karakter: %c%c\n",header.name[0],header.name[1]);
    printf("Size:%d\n",header.size);
    printf("Offset:%d\n",header.image_offset);
    
    fread(&dib,sizeof(struct DIB),1,fp);
    printf("Header size: %d\nWidth: %d\nHeight: %d\nColor planes: %d\nBits per pixel: %d\nCompression: %d\nImage size: %d\n",
            dib.dib_size,dib.width,dib.height,dib.colorplans,
            dib.bitsperpixel,dib.compression,dib.image_size);
    
    if ( (dib.dib_size != 40) && (dib.compression != 0) && (dib.bitsperpixel != 24)){
        fclose(fp);
        fprintf(stderr,"Hiba a fail megnyitása során");
        return;
    }
    
    fseek(fp,header.image_offset,SEEK_SET);
    struct Image image = readImage(fp,dib.height,dib.width);

    RGBimageToChar(image);

    fclose(fp);
    freeImage(image);
    
    //return 0; 
}




int main(){
    openbmpfile();

    return 0;
}