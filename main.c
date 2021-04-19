        /*
            esercitazione 0
            modularizzazione del calcolo del BMI su 5 individui

            spicoli piersilvio
        */

        #include <stdio.h>
        #include <stdlib.h>
        #include <time.h>

        #define per 5 //numero massimo di persone

        //costanti di minimo e massimo relativi a altezza e peso
        #define max_peso 120
        #define min_peso 60
        #define max_alt 200
        #define min_alt 160
        #define soglia 25

        //dichiarazione dei prototipi
        void gen(float a[]);
        float media(float a[]);
        float max(float a[]);
        void stampa(float a[]);

        //variabili globali
        int i;

        int main()
        {

            //variabili locali
            float bmi[per];
            float ma = 0.0;
            float med = 0.0;

            //inizializzazione
            for(i = 0; i < per; i++)
            {
                bmi[i] = 0.0;
            }

            //generazione
            gen(bmi);

            //calcolo media
            med = media(bmi);
            printf("\n\n_> media su 5 persone del BMI: %.2f \n", med);

            //ricerca lineare del massimo
            ma = max(bmi);
            printf("_> il massimo valore di BMI su 5 persone è: %.2f \n\n", ma);

            stampa(bmi);

            return 0;
        }

        void gen(float a[])
        {

            int i;
            float altezza = 0;
            float peso = 0;

            srand(time(NULL));

            for(i = 0; i < per; i++)
            {

                    altezza = rand()% (max_alt - min_alt + 1) + min_alt;
                    peso = rand()% (max_peso - min_peso + 1) + min_peso;
                    altezza /= 100.0; //per convertire in metri

                    a[i] = peso / (altezza * altezza);
            }
        }

        float media(float a[])
        {

            float m = 0.0;
            float s = 0.0;

            for(i = 0; i < per; i++)
            {
                s = s + a[i];
            }

            m = s / per; //calcolo media

            return m;
        }

        float max(float a[])
        {

            float max = 0.0;

            for(i = 0; i < per; i++)
            {
                if(a[i] > max)
                {
                    max = a[i];
                }
            }

            return max;
        }

        void stampa(float a[])
        {

            for(i = 0; i < per; i++)
            {

                printf("\t persona n° %d \n", i + 1);
                printf("\t BMI: %.2f", a[i]);

                if(a[i] > soglia)
                {
                    puts("_> sovrappeso");

                }else{

                    puts("_> sottopeso");
                }

                puts("\n");
            }
        }

