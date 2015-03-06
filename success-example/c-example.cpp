///////////////////////////////////////////////////////////
// Titulo : Juego Picas y Fijas                          //
// Autor : MaztoR                                         //
// Blog : Maztor.blogspot.com || MaztoR [In]-Security    //
// Twitter: @Mazt0r                                      //
// Fecha de creacion: [04/Octubre/2012]                  //
///////////////////////////////////////////////////////////

#include <cstdlib>
#include <time.h>
#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

int main()

{
  //Menu
  int opcionx;
  //Estados del Ciclo
  int status=0;
  int status2=0;
  // Rango Aleatorios
  int r1, r2;
  //Numero Generado
  int numero;
  //Numero Ingresao por el usuario
  int num_user;
  //Contadores
  int contador1, contador2;
  //Proceso con vectores aislamiento de cifras
  int n, residuo;
  //Vectores Numero Aleatorio Generado
  int agax, agax1, agax2, agax3, agax4, agax5;
  int nivel1[2], nivel2[3], nivel3[5];
  //Vectores Numero Aleatorio Ingresado por el usuario
  int auserx, auserx1, auserx2, auserx3, auserx4, auserx5;
  int iu[2], iu2[3], iu3[5];
  //Picas y Fijas
  int fijas=0, picas=0;
  //Intentos
  int intentos=0;

  system( "color 70" );

  //BANNER DE BIENVENIDA ASCII

  Beep ( 659 , 200);
  Beep ( 740 , 200);
  Sleep (800);
  cout<<"\n\t\t              .,-:;//;:=,"<<endl;
  cout<<"\t\t          . :H@@@MM@M#H/.,+%;,"<<endl;
  cout<<"\t\t       ,/X+ +M@@M@MM%=,-%HMMM@X/,"<<endl;
  Beep ( 784 , 200);
  cout<<"\t\t     -+@MM; $M@@MH+-,;XMMMM@MMMM@+-"<<endl;
  cout<<"\t\t    ;@M@@M- XM@X;. -+XXXXXHHH@M@M#@/."<<endl;
  cout<<"\t\t  ,%MM@@MH ,@%=            .---=-=:=,."<<endl;
  Beep ( 740 , 200);
  cout<<"\t\t  =@#@@@MX .,              -%HX$$%%%+;"<<endl;
  cout<<"\t\t =-./@M@M$    PICAS Y FIJAS .;@MMMM@MM:"<<endl;
  cout<<"\t\t X@/ -$MM/                    .+MM@@@M$"<<endl;
  Beep ( 659 , 200);
  cout<<"\t\t,@M@H: :@:                    . =X#@@@@-"<<endl;
  cout<<"\t\t,@@@MMX, .                    /H- ;@M@M="<<endl;
  Beep ( 659 , 200);
  cout<<"\t\t /MMMM@MMH/.                  XM@MH; =;"<<endl;
  cout<<"\t\t  /%+%$XHH@$=    MAZTOR    , .H@@@@MX,"<<endl;
  cout<<"\t\t   .=--------.           -%H.,@@@@@MX,"<<endl;
  Sleep (300);
  Beep ( 740 , 200);
  cout<<"\t\t   .%MM@@@HHHXX$$$%+- .:$MMX =M@@MM%."<<endl;
  cout<<"\t\t     =XMMM@MM@MM#H;,-+HMM@M+ /MMMX="<<endl;
  cout<<"\t\t      =%@M@M#@$-.=$@MM@@@M; %M%="<<endl;
  Beep ( 587 , 200);
  cout<<"\t\t        ,:+$+-,/H#MMMMMMM@= =,"<<endl;
  cout<<"\t\t              =++%%%%+/:-."<<endl;
  Sleep (300);
  Beep ( 659 , 200);
  Beep ( 440 , 200);
  Sleep (2000);
  system("cls");


  srand(time(NULL));

  //BUCLE PRINCIPAL || SE ROMPE CON EL STATUS

  do{
    //MENU PRINCIPAL
    cout<<"\t\t//////////////////////////////////////////////////"<<endl;
    cout<<"\t\t//                 Picas  y Fijas               //"<<endl;
    cout<<"\t\t--------------------------------------------------"<<endl;
    cout<<"\t\t//               1- Comenzar juego              //"<<endl;
    cout<<"\t\t//               2- Instrucciones               //"<<endl;
    cout<<"\t\t//               3- Creditos || Salir           //"<<endl;
    cout<<"\t\t//////////////////////////////////////////////////\n"<<endl;
    cout<<"\t\t                Seleccionar opcion: ";
    cin>>opcionx;

    //BUCLE OPCIONES SUBMENUS
    switch (opcionx)
  {
    //OPCIONES [COMENZAR JUEGO]
    case 1:
    system("cls");
    int subop;

    cout<<"\t\t//////////////////////////////////////////////////"<<endl;
    cout<<"\t\t//                 Picas  y Fijas               //"<<endl;
    cout<<"\t\t--------------------------------------------------"<<endl;
    cout<<"\t\t//               1- Facil [Padawan]             //"<<endl;
    cout<<"\t\t//               2- Intermedio [Jedi]           //"<<endl;
    cout<<"\t\t//               3- Dificil [Darth Vader]       //"<<endl;
    cout<<"\t\t//               4- Volver al Menu              //"<<endl;
    cout<<"\t\t//////////////////////////////////////////////////\n"<<endl;
    cout<<"\t\t                Seleccionar opcionx: ";
    cin>>subop;

    //SUBOPCIONES
    switch (subop)
  {

    //CASE 1 JUEGO [PRIMORDIALIDAD EN EL CODIGO]
    //JUEGO // TROZO DE CODIGO DELICADO

    case 1:
    system("cls");
    cout<<"\t\tEres un Novatillo, el maestro yoda te entrenara!!"<<endl;
    Sleep (3000);
    system("cls");
    Beep ( 659 , 200);
    cout<<"\t\t//////////////////////////////////////////////////"<<endl;
    cout<<"\t\t//                 Picas y Fijas                //"<<endl;
    cout<<"\t\t--------------------------------------------------"<<endl;
    cout<<"\t\t// La mision es encontrar el Numero de 3 Cifras //"<<endl;
    cout<<"\t\t--------------------------------------------------"<<endl;
    cout<<"\t\t//             Solo tienes 9  Intentos          //"<<endl;
    cout<<"\t\t//   El maestro Yoda te tiene en entrenamiento  //"<<endl;
    cout<<"\t\t--------------------------------------------------"<<endl;

    do{
      //Numero aleatorio
      status2=0;
      n=100; //Divisor
      r1 = 100;
      r2 = 999 + 1;
      numero = r1+rand()%(r2 - r1);

      cout<<"\t\t || Numero aleatorio generado > "<<numero<<endl;

      //Descomponer numero Dividiendo
      for (contador1=0;contador1<=2;contador1++)
      {
        nivel1[contador1] = numero/n;
        residuo = numero%n;
        numero = residuo;
        n = n/10;
      }

      agax=nivel1[0];
      agax1=nivel1[1];
      agax2=nivel1[2];

      //Descartando cifras repetidas en el numero generado
      for (contador1=0;contador1<=2;contador1++)
      {
        if(contador1>=1)
        {
          if(agax==nivel1[contador1])
          {
            status2=1;
          }
        }
        if(contador1>=2)
        {
          if(agax1==nivel1[contador1])
          {
            status2=1;
          }
        }
      }
    }while(status2==1);

    //Interaccion del Usuario

    do{
      fijas=0;
      picas=0;
      n=100;
      status2=0;

      cout<<"\t\t ||Digite un numero de 3 cifras > ";
      cin>>num_user;

      //Descomponer numero Dividiendo
      for (contador1=0;contador1<3;contador1++)
      {
        iu[contador1] = num_user/n;
        residuo = num_user%n;
        num_user = residuo;
        n = n/10;
      }

      auserx=iu[0];
      auserx1=iu[1];
      auserx2=iu[2];

      //Descartando cifras repetidas en el numero generado
      for (contador1=0;contador1<=2;contador1++)
      {
        if(contador1>=1)
        {
          if(auserx==iu[contador1])
          {
            status2=1;
          }
        }
        if(contador1>=2)
        {
          if(auserx1==iu[contador1])
          {
            status2=1;
          }
        }
      }

      if(status2==1)
      {
        cout<<"\t\t Alerta!! has Tecleado el mismo numero mas de una vez!!"<<endl;
      }else{


        //Fijas y picas
        for (contador1=0;contador1<=2;contador1++)
        {
          for(contador2=0;contador2<=2;contador2++)
          {

            if(iu[contador2]==nivel1[contador1])
            {

              if(contador2==contador1)
              {
                fijas++;
              }else{
                picas++;
              }
            }
          }
        }

        //Resultados sucesivos
        intentos++;
        cout<<"\t\t-------------------------------------------------"<<endl;
        cout<<"\t\t llevas "<<intentos<<" Intentos."<<endl;
        cout<<"\t\t Tienes "<<fijas<<" Fijas > y " <<picas<<" Picas. "<<fijas<<endl;
      }
      if(fijas==3)
      {
        status2=0;
      }else
      {
        status2=1;
      }
      if(intentos==9)
      {
        status2=0;
      }
    }while(status2!=0);

    //Resultados Finales
    if(fijas==3){
      system("cls");
      Sleep(1000);

      cout<<"						            .                            .                      ."<<endl;
      cout<<"                     .           ------=========---      .            ."<<endl;
      cout<<"                           -)----====    ,'   ,'   .                 ."<<endl;
      cout<<"              .                  `.  `.,;___,'                ."<<endl;
      cout<<"                                   |||||||||||| "<<endl;
      cout<<"                    _,.....------c==]""______ |,,,,,,.....____ _"<<endl;
      cout<<"    .      .       ____--------------------------------____-----"<<endl;
      cout<<"                                  ,'"",'.   `."<<endl;
      cout<<"         .                 -)-----====   `.   `.              LS"<<endl;
      cout<<"                     .           ------=========---      .            ."<<endl;
      cout<<"             .                               ."<<endl;
      Beep ( 740 , 200);
      Beep ( 740 , 200);
      Beep ( 740 , 200);
      Beep ( 740 , 200);
      Sleep(2000);
      system("cls");
      cout<<"         _____"<<endl;
      cout<<"       .'/L|__`."<<endl;
      cout<<"      | =[_]O|` |"<<endl;
      cout<<"      | +-------:|"<<endl;
      cout<<"    __:='|____`-:__        Felicitaciones la nave llego a Salvo!!"<<endl;
      cout<<"   ||[] ||====| []||"<<endl;
      cout<<"   ||[] | |=| | []||       Eres el honorable merecedor de ser un maestro jedi!!"<<endl;
      cout<<"   |:||_|=|U| |_||:|"<<endl;
      cout<<"   |:|||]_=_ =[_||:| "<<endl;
      cout<<"   | |||] [_][]C|| |"<<endl;
      cout<<"   ----------------- "<<endl;
      cout<<"   ||||||||||||||||| "<<endl;
      cout<<"  |___|   |||   |___|   "<<endl;
      cout<<"  `---'  |___|  `---'     "<<endl;
      cout<<"         `---'  "<<endl;


      intentos=0;
      Beep ( 740 , 200);
      cout<<"\n\t\tPresione enter para dirigirse al menu\n"<<endl;
      getch();
      system("cls");
    }
    if(intentos==9){
      system("cls");

      Sleep(1000);
      cout<<"						            .                            .                      ."<<endl;
      cout<<"                     .           ------=========---      .            ."<<endl;
      cout<<"                           -)----====    ,'   ,'   .                 ."<<endl;
      cout<<"              .                  `.  `.,;___,'                ."<<endl;
      cout<<"                                   |||||||||||| "<<endl;
      cout<<"                    _,.....------c==]""______ |,,,,,,.....____ _"<<endl;
      cout<<"    .      .       ____--------------------------------____-----"<<endl;
      cout<<"                                  ,'"",'.   `."<<endl;
      cout<<"         .                 -)-----====   `.   `.              LS"<<endl;
      cout<<"                     .           ------=========---      .            ."<<endl;
      cout<<"             .                               ."<<endl;
      Beep ( 740 , 200);
      Beep ( 740 , 200);
      Beep ( 740 , 200);
      Beep ( 740 , 200);
      Sleep(1000);
      system("cls");
      cout<<"\t\t\t      _.-^^---....,,--"<<endl;
      cout<<"\t\t\t  _--                  --_"<<endl;
      cout<<"\t\t\t  <                        >)"<<endl;
      cout<<"\t\t\t  |                         |"<<endl;
      cout<<"\t\t\t    ._                   _./"<<endl;
      cout<<"\t\t\t      ```--. . , ; .--'''"<<endl;
      cout<<"\t\t\t            | |   |"<<endl;
      cout<<"\t\t\t         .-=||  | |=-."<<endl;
      cout<<"\t\t\t         `-=#$%&%$#=-'"<<endl;
      cout<<"\t\t\t            | ;  :|"<<endl;
      cout<<"\t\t\t   _____.,-#%&$@%#&#~,._____ "<<endl;
      Sleep(1000);
      cout<<"\n\tLa nave ha sido Destruida!! No eres apto para ser maestro jedi\n"<<endl;
      intentos=0;
      Beep ( 740 , 200);
      cout<<"\n\t\tPresione enter para dirigirse al menu\n"<<endl;
      getch();
      system("cls");
    }
    break;




    case 2:
    system("cls");
    cout<<"\t\tCon que te crees un Maestro Jedi??  Te pondre a prueba!"<<endl;
    Sleep (3000);
    system("cls");
    Beep ( 659 , 200);
    cout<<"\t\t//////////////////////////////////////////////////"<<endl;
    cout<<"\t\t//                 Picas y Fijas                //"<<endl;
    cout<<"\t\t--------------------------------------------------"<<endl;
    cout<<"\t\t// La mision es encontrar el Numero de 4 Cifras //"<<endl;
    cout<<"\t\t--------------------------------------------------"<<endl;
    cout<<"\t\t//  Solo tienes 10 Intentos , Nuestro futuro... //"<<endl;
    cout<<"\t\t//    Esta en tus Manos... Confiamos en TI!     //"<<endl;
    cout<<"\t\t--------------------------------------------------"<<endl;

    do{

      status2=0;
      n=1000;

      r1 = 1000;
      r2 = 9999 + 1;
      numero = r1+rand()%(r2 - r1);
      cout<<"\t\t || Numero aleatorio generado > "<<numero<<endl;

      for (contador1=0;contador1<4;contador1++)
      {
        nivel2[contador1] = numero/n;
        residuo = numero%n;
        numero = residuo;
        n = n/10;
      }

      agax=nivel2[0];
      agax1=nivel2[1];
      agax2=nivel2[2];
      agax3=nivel2[3];


      for (contador1=0;contador1<=3;contador1++)
      {
        if(contador1>=1)
        {
          if(agax==nivel2[contador1])
          {
            status2=1;
          }
        }
        if(contador1>=2)
        {
          if(agax1==nivel2[contador1])
          {
            status2=1;
          }
        }
        if(contador1>=3)
        {
          if(agax2==nivel2[contador1])
          {
            status2=1;
          }
        }
      }
    }while(status2==1);



    do{
      fijas=0;
      picas=0;
      n=1000;
      status2=0;

      cout<<"\t\t ||Digite un numero de 4 cifras > ";
      cin>>num_user;

      for (contador1=0;contador1<4;contador1++)
      {
        iu2[contador1] = num_user/n;
        residuo = num_user%n;
        num_user = residuo;
        n = n/10;

      }

      auserx=iu2[0];
      auserx1=iu2[1];
      auserx2=iu2[2];
      auserx3=iu2[3];


      for (contador1=0;contador1<=3;contador1++)
      {
        if(contador1>=1)
        {
          if(auserx==iu2[contador1])
          {
            status2=1;
          }
        }
        if(contador1>=2)
        {
          if(auserx1==iu2[contador1])
          {
            status2=1;
          }
        }
        if(contador1>=3)
        {
          if(auserx2==iu2[contador1])
          {
            status2=1;
          }
        }
      }

      if(status2==1)
      {
        cout<<"\t\t Alerta!! has Tecleado el mismo numero mas de una vez!!"<<endl;
      }else
      {
        for (contador1=0;contador1<=3;contador1++)
        {
          for(contador2=0;contador2<=3;contador2++)
          {

            if(iu2[contador2]==nivel2[contador1])
            {

              if(contador2==contador1)
              {
                fijas++;
              }else
              {
                picas++;
              }
            }
          }
        }

        intentos++;
        cout<<"\t\t-------------------------------------------------"<<endl;
        cout<<"\t\t llevas "<<intentos<<" Intentos."<<endl;
        cout<<"\t\t Tienes "<<fijas<<" Fijas > y " <<picas<<" Picas. "<<fijas<<endl;

      }
      if(fijas==4)
      {
        status2=0;
      }else
      {
        status2=1;
      }
      if(intentos==10)
      {
        status2=0;
      }
    }while(status2!=0);

    if(fijas==4){
      system("cls");
      Sleep(1000);
      cout<<"						            .                            .                      ."<<endl;
      cout<<"                     .           ------=========---      .            ."<<endl;
      cout<<"                           -)----====    ,'   ,'   .                 ."<<endl;
      cout<<"              .                  `.  `.,;___,'                ."<<endl;
      cout<<"                                   |||||||||||| "<<endl;
      cout<<"                    _,.....------c==]""______ |,,,,,,.....____ _"<<endl;
      cout<<"    .      .       ____--------------------------------____-----"<<endl;
      cout<<"                                  ,'"",'.   `."<<endl;
      cout<<"         .                 -)-----====   `.   `.              LS"<<endl;
      cout<<"                     .           ------=========---      .            ."<<endl;
      cout<<"             .                               ."<<endl;
      Beep ( 740 , 200);
      Beep ( 740 , 200);
      Beep ( 740 , 200);
      Beep ( 740 , 200);
      Sleep(1000);
      system("cls");
      cout<<"         _____"<<endl;
      cout<<"       .'/L|__`."<<endl;
      cout<<"      | =[_]O|` |"<<endl;
      cout<<"      | +-------:|"<<endl;
      cout<<"    __:='|____`-:__        Felicitaciones la nave llego a Salvo!!"<<endl;
      cout<<"   ||[] ||====| []||"<<endl;
      cout<<"   ||[] | |=| | []||       Eres el honorable merecedor de ser un maestro jedi!!"<<endl;
      cout<<"   |:||_|=|U| |_||:|"<<endl;
      cout<<"   |:|||]_=_ =[_||:| "<<endl;
      cout<<"   | |||] [_][]C|| |"<<endl;
      cout<<"   ----------------- "<<endl;
      cout<<"   ||||||||||||||||| "<<endl;
      cout<<"  |___|   |||   |___|   "<<endl;
      cout<<"  `---'  |___|  `---'     "<<endl;
      cout<<"         `---'  "<<endl;


      intentos=0;
      Beep ( 740 , 200);
      cout<<"\n\t\tPresione enter para dirigirse al menu\n"<<endl;
      getch();
      system("cls");
    }
    if(intentos==10){
      system("cls");

      Sleep(1000);
      cout<<"						            .                            .                      ."<<endl;
      cout<<"                     .           ------=========---      .            ."<<endl;
      cout<<"                           -)----====    ,'   ,'   .                 ."<<endl;
      cout<<"              .                  `.  `.,;___,'                ."<<endl;
      cout<<"                                   |||||||||||| "<<endl;
      cout<<"                    _,.....------c==]""______ |,,,,,,.....____ _"<<endl;
      cout<<"    .      .       ____--------------------------------____-----"<<endl;
      cout<<"                                  ,'"",'.   `."<<endl;
      cout<<"         .                 -)-----====   `.   `.              LS"<<endl;
      cout<<"                     .           ------=========---      .            ."<<endl;
      cout<<"             .                               ."<<endl;
      Beep ( 740 , 200);
      Beep ( 740 , 200);
      Beep ( 740 , 200);
      Beep ( 740 , 200);
      Sleep(1000);
      system("cls");
      cout<<"\t\t\t      _.-^^---....,,--"<<endl;
      cout<<"\t\t\t  _--                  --_"<<endl;
      cout<<"\t\t\t  <                        >)"<<endl;
      cout<<"\t\t\t  |                         |"<<endl;
      cout<<"\t\t\t    ._                   _./"<<endl;
      cout<<"\t\t\t      ```--. . , ; .--'''"<<endl;
      cout<<"\t\t\t            | |   |"<<endl;
      cout<<"\t\t\t         .-=||  | |=-."<<endl;
      cout<<"\t\t\t         `-=#$%&%$#=-'"<<endl;
      cout<<"\t\t\t            | ;  :|"<<endl;
      cout<<"\t\t\t   _____.,-#%&$@%#&#~,._____ "<<endl;
      Sleep(1000);
      cout<<"\n\tLa nave ha sido Destruida!! No eres apto para ser maestro jedi\n"<<endl;
      intentos=0;
      Beep ( 740 , 200);
      cout<<"\n\t\tPresione enter para dirigirse al menu\n"<<endl;
      getch();
      system("cls");
    }
    break;

    case 3:
    system("cls");
    cout<<"\t\tSolo las almas oscuras seran capaces att: Darth vader"<<endl;
    Sleep (3000);
    system("cls");
    Beep ( 659 , 200);
    cout<<"              ________   ___   ____"<<endl;
    cout<<"             / __   __| | _ | |  _ | "<<endl;
    cout<<"       ______> | | |   |  _  ||    /_______________________________"<<endl;
    cout<<"      / _______/ |_|   |_| |_||_||______________________________ __| "<<endl;
    cout<<"     / /                                                         | | "<<endl;
    cout<<"    | |      La capacidad de destruir un planeta                 | |"<<endl;
    cout<<"    | |    es insignificante, comparada al poder de la fuerza    | |"<<endl;
    cout<<"    | |                                                          | |"<<endl;
    cout<<"    | |            Objetivos                                     | |"<<endl;
    cout<<"    | |               * Descifrar la clave de Obi-wan            | |"<<endl;
    cout<<"    | |               * hacerlo en 13 Intentos                   | |"<<endl;
    cout<<"    | |                                                          | |"<<endl;
    cout<<"    | |               Son 6 Digitos   y tenemos poco tiempo.     | |"<<endl;
    cout<<"    | |                                                          | |"<<endl;
    cout<<"    |_|__________________________________________________________|_|"<<endl;
    cout<<"      |___________________________________________________________/"<<endl;




    do{

      status2=0;
      n=100000;

      r1 = 100000;
      r2 = 999999 + 1;
      numero = r1+rand()%(r2 - r1);
      cout<<"\t\t || Numero aleatorio generado > "<<numero<<endl;

      for (contador1=0;contador1<6;contador1++)
      {
        nivel3[contador1] = numero/n;
        residuo = numero%n;
        numero = residuo;
        n = n/10;
      }

      agax=nivel3[0];
      agax1=nivel3[1];
      agax2=nivel3[2];
      agax3=nivel3[3];
      agax4=nivel3[4];
      agax5=nivel3[5];


      for (contador1=0;contador1<=5;contador1++)
      {
        if(contador1>=1)
        {
          if(agax==nivel3[contador1])
          {
            status2=1;
          }
        }
        if(contador1>=2)
        {
          if(agax1==nivel3[contador1])
          {
            status2=1;
          }
        }
        if(contador1>=3)
        {
          if(agax2==nivel3[contador1])
          {
            status2=1;
          }
        }
        if(contador1>=4)
        {
          if(agax3==nivel3[contador1])
          {
            status2=1;
          }
        }
        if(contador1>=5)
        {
          if(agax4==nivel3[contador1])
          {
            status2=1;
          }
        }

      }
    }while(status2==1);



    do{
      fijas=0;
      picas=0;
      n=100000;
      status2=0;


      cout<<"\t\t ||Digite un numero de 6 cifras > ";
      cin>>num_user;


      for (contador1=0;contador1<6;contador1++)
      {
        iu3[contador1] = num_user/n;
        residuo = num_user%n;
        num_user = residuo;
        n = n/10;

      }

      auserx=iu3[0];
      auserx1=iu3[1];
      auserx2=iu3[2];
      auserx3=iu3[3];
      auserx4=iu3[4];
      auserx5=iu3[5];


      for (contador1=0;contador1<=5;contador1++)
      {
        if(contador1>=1)
        {
          if(auserx==iu3[contador1])
          {
            status2=1;
          }
        }
        if(contador1>=2)
        {
          if(auserx1==iu3[contador1])
          {
            status2=1;
          }
        }
        if(contador1>=3)
        {
          if(auserx2==iu3[contador1])
          {
            status2=1;
          }
        }
        if(contador1>=4)
        {
          if(auserx3==iu3[contador1])
          {
            status2=1;
          }
        }
        if(contador1>=5)
        {
          if(auserx4==iu3[contador1])
          {
            status2=1;
          }
        }
      }

      if(status2==1)
      {
        cout<<"\t\t Alerta!! has Tecleado el mismo numero mas de una vez!!"<<endl;
      }else{
        for (contador1=0;contador1<6;contador1++)
        {
          for(contador2=0;contador2<6;contador2++)
          {

            if(iu3[contador2]==nivel3[contador1])
            {

              if(contador2==contador1)
              {
                fijas++;
              }else
              {
                picas++;
              }
            }
          }
        }

        intentos++;
        cout<<"\t\t-------------------------------------------------"<<endl;
        cout<<"\t\t llevas "<<intentos<<" Intentos."<<endl;
        cout<<"\t\t Tienes "<<fijas<<" Fijas > y " <<picas<<" Picas. "<<fijas<<endl;

      }
      if(fijas==6)
      {
        status2=0;
      }else{
        status2=1;
      }
      if(intentos==13)
      {
        status2=0;
      }
    }while(status2!=0);


    if(fijas==6)
    {
      system("cls");
      Sleep(1000);
      cout<<"\t   _________________________________ "<<endl;
      cout<<"\t  |:::::::::::::;;::::::::::::::::::| "<<endl;
      cout<<"\t  |:::::::::::'~||~~~``:::::::::::::| "<<endl;
      cout<<"\t  |::::::::'   .':     o`:::::::::::| "<<endl;
      cout<<"\t  |:::::::' oo | |o  o    ::::::::::| "<<endl;
      cout<<"\t  |::::::: 8  .'.'    8 o  :::::::::| "<<endl;
      cout<<"\t  |::::::: 8  | |     8    :::::::::| "<<endl;
      cout<<"\t  |::::::: _._| |_,...8    :::::::::| Ya Perteneces al lado oscuro."<<endl;
      cout<<"\t  |::::::'~--.   .--. `.   `::::::::| "<<endl;
      cout<<"\t  |:::::'     =8     ~    o ::::::::| "<<endl;
      cout<<"\t  |::::'       8._ 88.     o::::::::| "<<endl;
      cout<<"\t  |:::'   __. ,.ooo~~.      o`::::::| "<<endl;
      cout<<"\t  |:::   . -. 88`78o/:        `:::::|  Sigue mis instrucciones o      "<<endl;
      cout<<"\t  |::'     /. o o   ::       88`::::|           tendre que destruirte"<<endl;
      cout<<"\t  |:;     o|| 8 8 |d.        `8 `:::| "<<endl;
      cout<<"\t  |:.       - ^ ^ -'           `-`::| "<<endl;
      cout<<"\t  |::.                          .:::| "<<endl;
      cout<<"\t  |:::::.....           ::'     ``::| "<<endl;
      cout<<"\t  |::::::::-'`-        88          `| "<<endl;
      cout<<"\t  |:::::-'.          -       ::     | "<<endl;
      cout<<"\t  |:-~. . .                   :     | "<<endl;
      cout<<"\t  |_________________________________|"<<endl;
      cout<<"\n\t\tPresione enter para dirigirse al menu\n"<<endl;
      getch();
      system("cls");
      intentos=0;
    }
    if(intentos==13)
    {
      system("cls");
      Sleep(1000);

      cout<<"\t        ____________ __________________ ___________"<<endl;
      cout<<"\t       |           FRACASADOOOOOOOOOOOOOO         |"<<endl;
      cout<<"\t       | -""  Moriras por hacerme perder el tiempo|"<<endl;
      cout<<"\t      .-|  . )     (                              |"<<endl;
      cout<<"\t     j   .'_+     :[                )      .^--.. |"<<endl;
      cout<<"\t    i    -""       |l                ].    /       i|"<<endl;
      cout<<"\t   ,"".:j         ||o  _,,+.,.--,   d|    :::;    b"<<endl;
      cout<<"\t   i  :'|          ""--p;.  (-._"".oP        .   :" <<endl;
      cout<<"\t   ; .  (            >,%%%   f),):8""          :'  i" <<endl;
      cout<<"\t  i  :: j          ,;%%%:; ; ; i:%%%.,        i.   `."<<endl;
      cout<<"\t  i  `: ( ____  ,-::::::' ::j  [:```          [8:   )"<<endl;
      cout<<"\t  <  ..``'::::8888oooooo.  :(jj(,;,,,         [8::  <"<<endl;
      cout<<"\t  `. ``:.      oo.8888888888:;%%%8o.::.+888+o.:`:'  |"<<endl;
      cout<<"\t   `.   `        `o`88888888b`%%%%%88< Y888P""'-    ;"<<endl;
      cout<<"\t      --- .       Y888888888., 88b..::::        _   :  "<<endl;
      cout<<"\t       |    ""....  b`8888888:::::.`8888._::-""   |"<<endl;
      cout<<"\t       |       `:::. `:::::O:::::::.`%%'|         |"<<endl;
      cout<<"\t       |        `.      ""``::::::''    .'        |"<<endl;
      cout<<"\t       |          `.                   <          |"<<endl;
      cout<<"\t       |            +:         `:   -';           |"<<endl;
      cout<<"\t       |  ____       `:         : .::/            |"<<endl;
      cout<<"\t       | `-|--        ;+_  :::. :..;;;         LS |"<<endl;
      cout<<"\t       |______________;;;;,;;;;;;;;,;;____________|"<<endl;
      cout<<"\n\t\tPresione enter para dirigirse al menu\n"<<endl;
      getch();
      system("cls");
      intentos=0;
    }
    break;

    case 4:   system("cls");
    break;
    default: system("cls"); Beep( 790, 300 ); cout<<"\t\tNo Intentes nada RARO Te devolvere al menu principal!"; Sleep(3000);
    system("cls");

  }
  break;

  //opcionx2 [INSTRUCCIONES]
  case 2:
  system("cls");
  int subop2;
  cout<<"\t/////////////////////////////////////////////////////////////"<<endl;
  cout<<"\t//                      INSTRUCCIONES                      //"<<endl;
  cout<<"\t---------------------------------------------------------- //"<<endl;
  cout<<"\t---------------------------------------------------------- //"<<endl;
  cout<<"\t// El sistema calculara una cadena de numeros de [3,4 o 6] //"<<endl;
  cout<<"\t// Cifras, a su vez, los jugadores tratan de adivinar      //"<<endl;
  cout<<"\t// el número de su oponente [Maquina].Si las cifras son    //"<<endl;
  cout<<"\t// coincidentes en sus posiciones correctas, son *Fijas*,  //"<<endl;
  cout<<"\t// Si, en diferentes posiciones, son *Picas*.              //"<<endl;
  cout<<"\t//                                                         //"<<endl;
  cout<<"\t// Ejemplo:   El numero secreto: 4271                      //"<<endl;
  cout<<"\t//            Intento del oponente: 1234                   //"<<endl;
  cout<<"\t//                                                         //"<<endl;
  cout<<"\t// Respuesta: (La fija es '2', las picas son '4' y '1'.)   //"<<endl;
  cout<<"\t---------------------------------------------------------- //"<<endl;
  cout<<"\t---------------------------------------------------------- //"<<endl;
  cout<<"\t/////////////////////////////////////////////////////////////\n"<<endl;
  cout<<"\t      Presione la tecla '1' para volver al menu: ";
  cin>>subop2;
  //SUBopcionxES
  switch (subop2)
{
  case 1:   system("cls"); break;
  default: system("cls"); Beep( 790, 300 ); cout<<"\t\tNo Intentes nada RARO Te devolvere al menu principal!"; Sleep(3000);
  system("cls");



}
break;


//opcionx3 [CREDITOS - SALIR]
case 3:
system("cls");

Beep( 790, 300 ); Sleep(1000);cout<<"\t/////////////////////////////////////////////////////////////"<<endl;    
Beep( 790, 300 ); Sleep(1000);cout<<"\t//                      Creador                            //"<<endl;
Beep( 790, 300 ); Sleep(1000);cout<<"\t---------------------------------------------------------- //"<<endl;
Beep( 790, 300 );  Sleep(1000);cout<<"\t---------------------------------------------------------- //"<<endl;
Beep( 790, 300 ); Sleep(1000);cout<<"\t//                      MaztoR [IN]-Security               //"<<endl;
Beep( 790, 300 ); Sleep(1000);cout<<"\t//              [Maztor.Blogspot.com]                      //"<<endl;
Beep( 790, 300 ); Sleep(1000);cout<<"\t//---------------------------------------------------------//"<<endl;
Beep( 790, 300 ); Sleep(1000);cout<<"\t/////////////////////////////////////////////////////////////\n\n"<<endl;




Beep( 800, 800 ); status=1;

break;


default: system("cls"); Beep( 790, 300 ); cout<<"\t\tNo Sabes leer??? No existe esta opcionx -.-!"; Sleep(3000);
system("cls");


}


}while(status==0);






system("PAUSE");
return 0;
}
