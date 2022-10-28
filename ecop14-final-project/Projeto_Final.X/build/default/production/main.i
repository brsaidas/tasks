# 1 "main.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Program Files (x86)/Microchip/MPLABX/v5.35/packs/Microchip/PIC18Fxxxx_DFP/1.2.26/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "main.c" 2
# 1 "./adc.h" 1
# 22 "./adc.h"
 void adcInit(void);
 int adcRead(unsigned int channel);
# 1 "main.c" 2

# 1 "./lcd.h" 1


  void lcdCommand(char value);
  void lcdChar(char value);
  void lcdString(char msg[]);
  void lcdNumber(int value);
  void lcdPosition(int line, int col);
  void lcdInit(void);
# 2 "main.c" 2

# 1 "./atraso.h" 1



void atraso_ms(unsigned int num);
# 3 "main.c" 2

# 1 "./keypad.h" 1


 unsigned int kpRead(void);
    char kpReadKey(void);
 void kpDebounce(void);
 void kpInit(void);
# 4 "main.c" 2

# 1 "./serial.h" 1
# 23 "./serial.h"
 void serialSend(unsigned char c);
 unsigned char serialRead(void);
 void serialInit(void);
# 5 "main.c" 2
# 17 "main.c"
unsigned char leTeclado(void);
void leADC(unsigned char Max, unsigned char Min);

unsigned char leSerial(void);
unsigned char serialReadChar(void);
void serialSendString(char String[]);

void main(void){
    unsigned char Slot = 0;
    unsigned char Superfice = 0;
    unsigned char Max[3], Min[3];

    kpInit();
    adcInit();
    lcdInit();
    serialInit();


    lcdCommand(0x01);
    lcdCommand(0x80);
    lcdString("Aileron");
    lcdCommand(0xC0);
    lcdString("MAX: ");

    serialSendString("Aileron\n");
    serialSendString("MAX: ");

    Max[0] = leSerial();

    lcdNumber(Max[0]);

    serialSend((Max[0]/10) % 10 + '0');
    serialSend((Max[0]/1) % 10 + '0');
    serialSend('\n');

    atraso_ms(2000);

    lcdCommand(0x01);
    lcdCommand(0x80);
    lcdString("Aileron");
    lcdCommand(0xC0);
    lcdString("MIN: ");

    serialSendString("MIN: ");

    Min[0] = leSerial();

    lcdNumber(Min[0]);

    serialSend((Min[0]/10) % 10 + '0');
    serialSend((Min[0]/1) % 10 + '0');
    serialSend('\n');

    atraso_ms(2000);



    lcdCommand(0x01);
    lcdCommand(0x80);
    lcdString("Profundor");
    lcdCommand(0xC0);
    lcdString("MAX: ");

    serialSendString("Profundor\n");
    serialSendString("MAX: ");

    Max[1] = leSerial();

    lcdNumber(Max[1]);

    serialSend((Max[1]/10) % 10 + '0');
    serialSend((Max[1]/1) % 10 + '0');
    serialSend('\n');

    atraso_ms(2000);

    lcdCommand(0x01);
    lcdCommand(0x80);
    lcdString("Profundor");
    lcdCommand(0xC0);
    lcdString("MIN: ");

    serialSendString("MIN: ");

    Min[1] = leSerial();

    lcdNumber(Min[1]);

    serialSend((Min[1]/10) % 10 + '0');
    serialSend((Min[1]/1) % 10 + '0');
    serialSend('\n');

    atraso_ms(2000);




    lcdCommand(0x01);
    lcdCommand(0x80);
    lcdString("Leme");
    lcdCommand(0xC0);
    lcdString("MAX: ");

    serialSendString("Leme\n");
    serialSendString("MAX: ");

    Max[2] = leSerial();

    lcdNumber(Max[2]);

    serialSend((Max[2]/10) % 10 + '0');
    serialSend((Max[2]/1) % 10 + '0');
    serialSend('\n');

    atraso_ms(2000);

    lcdCommand(0x01);
    lcdCommand(0x80);
    lcdString("Leme");
    lcdCommand(0xC0);
    lcdString("MIN: ");

    serialSendString("MIN: ");

    Min[2] = leSerial();

    lcdNumber(Min[2]);

    serialSend((Min[2]/10) % 10 + '0');
    serialSend((Min[2]/1) % 10 + '0');
    serialSend('\n');

    atraso_ms(2000);



    lcdCommand(0x01);
    lcdCommand(0x80);
    lcdString("Aileron: ");

    for(;;){
        switch(Slot){
            case 0:
                kpDebounce();

                Slot = 1;
                break;
            case 1:
                Superfice = leTeclado();

                Slot = 2;
                break;
            case 2:
                leADC(Max[Superfice], Min[Superfice]);

                Slot = 0;
                break;
            default:
                Slot = 0;
                break;
        }
    }
}

unsigned char leTeclado(void){
    static unsigned int Leitura = 0;
    static unsigned char Retorno = 0;

    if(kpRead() != Leitura){
        Leitura = kpRead();

        switch(kpReadKey()){
            case 'U':
                lcdCommand(0x01);
                lcdString("Aileron:");
                Retorno = 0;
                break;
            case 'L':
                lcdCommand(0x01);
                lcdString("Profundor:");
                Retorno = 1;
                break;
            case 'D':
                lcdCommand(0x01);
                lcdString("Leme:");
                Retorno = 2;
                break;
            default:
                break;
        }
    }

    return Retorno;
}

void leADC(unsigned char Max, unsigned char Min){
    int ValorADC = adcRead(0);

    int x = (float) (((Max - Min)*(ValorADC/1023.0)) + Min);

    lcdCommand(0xC0);
    lcdChar((x / 1000) % 10 + '0');
    lcdChar((x / 100) % 10 + '0');
    lcdChar((x / 10) % 10 + '0');
    lcdChar((x / 1) % 10 + '0');
    lcdString(" Graus");
}

unsigned char leSerial(void){
    unsigned char Input[3];

    Input[0] = serialReadChar();
    Input[1] = serialReadChar();
    Input[2] = serialReadChar();

    return (Input[0] - '0')*10 + Input[1] - '0';
}

void serialSendString(char String[]){
    char i = 0;

    while(String[i] != '\0'){
        serialSend(String[i]);
        i++;
    }
}

unsigned char serialReadChar(void){
    unsigned char Byte;

    while(1){
        Byte = serialRead();

        if(Byte != 0) return Byte;
    }
}
