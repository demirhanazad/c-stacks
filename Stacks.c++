// BİSMİLLAHİRRAHMANİRRAHİM
// Demirhan Adıgüzel'in C Ders Ödevi
#include <stdio.h>
#include <cstdlib>
#include <string.h>
int Yiginin_index_no=0;//yıgın döngüsünün baslama degeri girilir
int kapasite;//Yıgının kapasitesi yazdırılır
void Pop();
struct yigin//Burada yigin adında verileri saklayan bir struct tanımlıyoruz sadece bir veri içinde tutabilmesine izin verilen bir struct
{
    int veri;
    struct yigin* sonraki=NULL;//veya 0
};
struct yigin* Basla;//structımıza Basla pointer ile baslatıyoruz
void Pop(){ //struct'ın verilerini içinde barındıran yapı fonksiyonu bu fonksiyon icine gonderdigimiz veri degerini structaki veri kısmına yazdırır
    if (Basla==NULL){
        printf("Yigin Bos Oldugundan Eleman Cikarilamaz");
    }
    else {
        Yiginin_index_no-=1;
        int x=Basla->veri;//Son Degerin adresi
        struct yigin* temp=Basla;
        Basla=Basla->sonraki;
        printf("Yigindan cikarilan deger : [|%d|]",x);
        free(temp);
        //fonksiyonumuzu dugum adlı yolu geri döndürecek şekilde bitiriyoruz
    }
}
void Top(){ //struct'ın verilerini içinde barındıran yapı fonksiyonu bu fonksiyon icine gonderdigimiz veri degerini structaki veri kısmına yazdırır
    if (Basla==NULL){
        printf("Yiginda Eleman Kalmadi");
    }
    else {
        int x=Basla->veri;//Son Degerin adresi
        printf("Yigindan Ilk Cikmasi Beklenilen Deger : [|%d|]",x);
        //fonksiyonumuzu dugum adlı yolu geri döndürecek şekilde bitiriyoruz
    }
}
struct yigin* yeniDugum(int veri)//struct'ın verilerini içinde barındıran yapı fonksiyonu bu fonksiyon icine gonderdigimiz veri degerini structaki veri kısmına yazdırır
{
  struct yigin* dugum = (struct yigin*)malloc(sizeof(struct yigin));//bellekten dugum icin struct yıgin kadar alan ayırmamıza yarıyor
  dugum->veri=veri;//dugum pointer structının veri degerine fonksiyona gönderilen int veri degerini eklemeye yarar
  dugum->sonraki = 0;//veya NULL//sonraki eklenecek yolu boş olarak belirtiyoruz
  return(dugum);//fonksiyonumuzu dugum adlı yolu geri döndürecek şekilde bitiriyoruz
}
void Yigina_Ekleme_Yap(){
    int kontrol_noktası=0;
    int soru_sorma_miktar_degeri;
    int x;
    //struct yigin* yenidugum=yeniDugum(3);
    //Basla=yeniDugum;
    if (Yiginin_index_no<kapasite){
        printf("Yigina Eklenecek Miktari Giriniz");
        scanf("%d",&soru_sorma_miktar_degeri);
        if (Yiginin_index_no+soru_sorma_miktar_degeri<=kapasite){
            while (kontrol_noktası<soru_sorma_miktar_degeri){
                Yiginin_index_no+=1;
                kontrol_noktası+=1;
                //struct yigin* eklenecekDugum = yeniDugum(7);
                if(Basla == NULL){
                    printf("Yigina ilk degeri giriniz");
                    scanf("%d",&x);
                    Basla = yeniDugum(x);
                }
                else
                {
                    struct yigin* temp = Basla;
                    printf("Yigina eklenecek sonraki degeri giriniz");
                    scanf("%d",&x);
                    Basla = yeniDugum(x);
                    Basla->sonraki = temp;
                }
            }
        }
        else{
            printf("\n#########################################################################\n");
            printf("#Girilen Degerler Toplami Kapasiteyi Asiyor Girilebilecek Deger Sayisi %d#\n",kapasite-(Yiginin_index_no));
            printf("##########################################################################\n");
        }
    }
    else{
        printf("\n########################################\n");
        printf("#Yigin Kapasitesi Dolu Ekleme Yapilamaz#\n");
        printf("########################################\n");
    }

}
void Yigin_Yazdir(){
    printf("\nYigina girilen degerler : [");
    struct yigin* temp_2 = Basla;
    while (temp_2){
        printf(" |%d| ", temp_2->veri);
        temp_2=temp_2->sonraki;
    }
    printf("]\n");
}
int main()
{
    int dongu_degeri=0;
    while(dongu_degeri<=0){
        char str[] = "\nYigina Deger Ekleme,Yigin Yazdirma,Cikis,isEmty,Pop,Top";
        int Secilen_Islem;
        // Returns first token 
        char *token = strtok(str, ",");
        // Keep printing tokens while one of the
        // delimiters present in str[].
        for (int i=1;i<=6;i++)
        {
            printf("%s icin %d 'e basiniz...\n", token,i);
            token = strtok(NULL, ",");
        }
        scanf("%d",&Secilen_Islem);
        
        switch(Secilen_Islem){
            case 1:{
                if(Basla == NULL){
                printf("Yigin kapasitesi giriniz");
                scanf("%d",&kapasite);
            }
                Yigina_Ekleme_Yap();};
            break;
            case 2:Yigin_Yazdir();
            break;
            case 3:dongu_degeri+=1;
            break;
            case 4:{
                if (Basla == NULL){
                    printf("Yigin Bos");
                }
                else{
                    printf("Yigin Doluluk degeri %d / %d",Yiginin_index_no,kapasite);
                }
            };
            break;
            case 5:Pop();
            break;
            case 6:Top();
            break;
            default:printf("boyle islem mevcut degil");
        }
    }
    
    return 0;
}
