#include "adc.h"
#include "lcd.h"
#include "atraso.h"
#include "keypad.h"
#include "serial.h"

#define L_ON  0x0F
#define L_L1  0x80
#define L_L2  0xC0
#define L_CLR 0x01
#define L_OFF 0x08

#define AILERON 0
#define PROFUNDOR 1
#define LEME 2

unsigned char leTeclado(void);
void leADC(unsigned char Max, unsigned char Min);

unsigned char leSerial(void);
unsigned char serialReadChar(void);
void serialSendString(char String[]);

void main(void){
    unsigned char Slot = 0;
    unsigned char Superfice = AILERON;
    unsigned char Max[3], Min[3];
    
    kpInit();
    adcInit();
    lcdInit();
    serialInit();
        
    /*********************Aileron**********************/
    lcdCommand(L_CLR);
    lcdCommand(L_L1);
    lcdString("Aileron");
    lcdCommand(L_L2);
    lcdString("MAX: ");
    
    serialSendString("Aileron\n");
    serialSendString("MAX: ");
    
    Max[AILERON] = leSerial();
    
    lcdNumber(Max[AILERON]);
    
    serialSend((Max[AILERON]/10) % 10 + '0');
    serialSend((Max[AILERON]/1)  % 10 + '0');
    serialSend('\n');
    
    atraso_ms(2000);
    
    lcdCommand(L_CLR);
    lcdCommand(L_L1);
    lcdString("Aileron");
    lcdCommand(L_L2);
    lcdString("MIN: ");
    
    serialSendString("MIN: ");
    
    Min[AILERON] = leSerial();
    
    lcdNumber(Min[AILERON]);
    
    serialSend((Min[AILERON]/10) % 10 + '0');
    serialSend((Min[AILERON]/1)  % 10 + '0');
    serialSend('\n');
    
    atraso_ms(2000);
    //*********************Fim Aileron********************
    
    //*********************Profundor**********************
    lcdCommand(L_CLR);
    lcdCommand(L_L1);
    lcdString("Profundor");
    lcdCommand(L_L2);
    lcdString("MAX: ");
    
    serialSendString("Profundor\n");
    serialSendString("MAX: ");
    
    Max[PROFUNDOR] = leSerial();
    
    lcdNumber(Max[PROFUNDOR]);
    
    serialSend((Max[PROFUNDOR]/10) % 10 + '0');
    serialSend((Max[PROFUNDOR]/1)  % 10 + '0');
    serialSend('\n');
    
    atraso_ms(2000);
    
    lcdCommand(L_CLR);
    lcdCommand(L_L1);
    lcdString("Profundor");
    lcdCommand(L_L2);
    lcdString("MIN: ");
    
    serialSendString("MIN: ");
    
    Min[PROFUNDOR] = leSerial();
    
    lcdNumber(Min[PROFUNDOR]);
    
    serialSend((Min[PROFUNDOR]/10) % 10 + '0');
    serialSend((Min[PROFUNDOR]/1)  % 10 + '0');
    serialSend('\n');
    
    atraso_ms(2000);
    
    //*********************Fim Profundor**********************
    
    //*********************Leme**********************
    lcdCommand(L_CLR);
    lcdCommand(L_L1);
    lcdString("Leme");
    lcdCommand(L_L2);
    lcdString("MAX: ");
    
    serialSendString("Leme\n");
    serialSendString("MAX: ");
    
    Max[LEME] = leSerial();
    
    lcdNumber(Max[LEME]);
    
    serialSend((Max[LEME]/10) % 10 + '0');
    serialSend((Max[LEME]/1)  % 10 + '0');
    serialSend('\n');
    
    atraso_ms(2000);
    
    lcdCommand(L_CLR);
    lcdCommand(L_L1);
    lcdString("Leme");
    lcdCommand(L_L2);
    lcdString("MIN: ");
    
    serialSendString("MIN: ");
    
    Min[LEME] = leSerial();
    
    lcdNumber(Min[LEME]);
    
    serialSend((Min[LEME]/10) % 10 + '0');
    serialSend((Min[LEME]/1)  % 10 + '0');
    serialSend('\n');
    
    atraso_ms(2000);
    
    //*********************Fim Leme**********************
    
    lcdCommand(L_CLR);
    lcdCommand(L_L1);
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
    static unsigned char Retorno = AILERON;
   
    if(kpRead() != Leitura){
        Leitura = kpRead();
        
        switch(kpReadKey()){
            case 'U':
                lcdCommand(L_CLR);
                lcdString("Aileron:");
                Retorno = AILERON;
                break;
            case 'L':
                lcdCommand(L_CLR);
                lcdString("Profundor:");
                Retorno = PROFUNDOR;
                break;
            case 'D':
                lcdCommand(L_CLR);
                lcdString("Leme:");
                Retorno = LEME;
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
    
    lcdCommand(L_L2);
    lcdChar((x / 1000) % 10 + '0');       
    lcdChar((x / 100)  % 10 + '0');
    lcdChar((x / 10)   % 10 + '0');
    lcdChar((x / 1)    % 10 + '0');
    lcdString(" Graus");
}

unsigned char leSerial(void){
    unsigned char Input[3];
    
    Input[0] = serialReadChar();
    Input[1] = serialReadChar();
    Input[2] = serialReadChar(); // Caractere '\n'
    
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