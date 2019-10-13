              

// Arduino digital pin assignment
const int P0 =  2;      
const int P1 =  3;      
const int P2 =  4;      
const int P3 =  5;

const int N0 =  6;   
const int N1 =  7;      
const int N2 =  8;      
              
const int Button1=10;
const int Button2=11;
const int Buzzer=12;
              
int button1State = HIGH;
int button2State = HIGH;
              
int solstate[13]={0,0,0,0,0,0,0,0,0,0,0,0};

int book_pointer = 0;
int book_mode = 0;

int time = 1200;

char inByte=0;

char text[150] = "Where's Papa going with the ax? said Fern to her mother asthey were setting the table for breakfast.";
           
 void setup() {
                 // start up tone
                   tone(12,1000,500);
     
                   pinMode(P0, OUTPUT);      
                   pinMode(P1, OUTPUT);      
                   pinMode(P2, OUTPUT);      
                   pinMode(P3, OUTPUT);  
                   pinMode(N0, OUTPUT);      
                   pinMode(N1, OUTPUT);      
                   pinMode(N2, OUTPUT);     
                   pinMode(Button1, INPUT);      
                   pinMode(Button2, INPUT);      
                   pinMode(Buzzer, OUTPUT);
                   
  
                   digitalWrite(P0, LOW);  
                   digitalWrite(P1, LOW);   
                   digitalWrite(P2, LOW);   
                   digitalWrite(P3, LOW); 
                   
                   digitalWrite(N0, LOW);  
                   digitalWrite(N1, LOW);   
                   digitalWrite(N2, LOW);   
                   
                   digitalWrite(Buzzer, LOW);  
                  
                   Serial.begin(9600);
                   while (!Serial) {
                     ;
                   }
          
                   establishContact();  
}        

void loop()
{
          button_process();

            if (Serial.available() > 0) {
              // get incoming byte:
              inByte = Serial.read();
              Serial.println(inByte);  
               
              if(book_mode == 1) {
             //     Serial.println("BookMode Off");
                  book_mode = 0;
              }
            }
                       
            if(book_mode == 1) {
                asc2br(text[book_pointer], 0);    // left
                asc2br(text[book_pointer+1], 1);  // right
            } else {
                solstate[0]=0;
                solstate[1]=0;
                solstate[2]=0;
                solstate[3]=0;
                solstate[4]=0;
                solstate[5]=0;
                solstate[6]=0;
                solstate[7]=0;
                solstate[8]=0;
                solstate[9]=0;
                solstate[10]=0;
                solstate[11]=0;
                asc2br(inByte, 0);  // left
                asc2br(inByte, 1);  // right
            }
            printbr(time);
}
     
void asc2br(char myChar, int location){
              
               // lower to upper case
              if(myChar<='z' && myChar>='a'){
                      myChar=myChar-32;
              }
                       
              switch(myChar){
                case 'A':
                solstate[0+2*location]=1;
                break;
               
                case 'B':
                solstate[0+2*location]=1;
                solstate[4+2*location]=1;
                break;
               
                case 'C':
                solstate[0+2*location]=1;
                solstate[1+2*location]=1;
                break;
               
                case 'D':
                solstate[0+2*location]=1;
                solstate[1+2*location]=1;
                solstate[5+2*location]=1;
                break;
               
                case 'E':    
                solstate[0+2*location]=1;
                solstate[5+2*location]=1;
                break;
              
                case 'F':
                solstate[0+2*location]=1;
                solstate[1+2*location]=1;
                solstate[4+2*location]=1;
                break;
               
                case 'G':    
                solstate[0+2*location]=1;
                solstate[1+2*location]=1;
                solstate[4+2*location]=1;
                solstate[5+2*location]=1;
                break;
               
                case 'H':
                solstate[0+2*location]=1;
                solstate[4+2*location]=1;
                solstate[5+2*location]=1;
                break;
               
                case 'I':    
                solstate[1+2*location]=1;
                solstate[4+2*location]=1;
                break;
                
                case 'J':    
                solstate[1+2*location]=1;
                solstate[4+2*location]=1;
                solstate[5+2*location]=1;
                break;
                
                case 'K':    
                solstate[0+2*location]=1;
                solstate[8+2*location]=1;
                break;
               
                case 'L':    
                solstate[0+2*location]=1;
                solstate[4+2*location]=1;
                solstate[8+2*location]=1;
                break;
                
                
                
                case 'M':    
                solstate[0+2*location]=1;
                solstate[1+2*location]=1;
                solstate[8+2*location]=1;
             
                break; 
                case 'N':    
                solstate[0+2*location]=1;
                solstate[1+2*location]=1;
                solstate[5+2*location]=1;
                solstate[8+2*location]=1;
             
                break;
              
                case 'O':    
                solstate[0+2*location]=1;
                solstate[5+2*location]=1;
                solstate[8+2*location]=1;
                break;
               
                case 'P':    
                solstate[0+2*location]=1;
                solstate[1+2*location]=1;
                solstate[4+2*location]=1;
                solstate[8+2*location]=1;
                break;
              
                case 'Q':    
                solstate[0+2*location]=1;
                solstate[1+2*location]=1;
                solstate[4+2*location]=1;
                solstate[5+2*location]=1;
                solstate[8+2*location]=1;
                break;
              
                case 'R':    
                solstate[0+2*location]=1;
                solstate[4+2*location]=1;
                solstate[5+2*location]=1;
                solstate[8+2*location]=1;
                break;
             
                case 'S':    
                solstate[0+2*location]=1;
                solstate[4+2*location]=1;
                solstate[8+2*location]=1;
                break;
              
                case 'T':    
                solstate[1+2*location]=1;
                solstate[4+2*location]=1;
                solstate[5+2*location]=1;
                solstate[8+2*location]=1;
                break;
               
                case 'U':    
                solstate[0+2*location]=1;
                solstate[8+2*location]=1;
                solstate[9+2*location]=1;
                break;
                
                case 'V':    
                solstate[0+2*location]=1;
                solstate[4+2*location]=1;
                solstate[8+2*location]=1;
                solstate[9+2*location]=1;
                break;
               
                case 'W':    
                solstate[1+2*location]=1;
                solstate[5+2*location]=1;
                solstate[4+2*location]=1;
                solstate[9+2*location]=1;
                break;
               
                case 'X':    
                solstate[0+2*location]=1;
                solstate[1+2*location]=1;
                solstate[8+2*location]=1;
                solstate[9+2*location]=1;
                break;
               
                case 'Y':    
                solstate[0+2*location]=1;
                solstate[1+2*location]=1;
                solstate[8+2*location]=1;
                solstate[9+2*location]=1;
                solstate[5+2*location]=1;
                break;
               
                case 'Z':    
                solstate[0+2*location]=1;
                solstate[5+2*location]=1;
                solstate[8+2*location]=1;
                solstate[9+2*location]=1;
                break;
                
                case '1':
                solstate[4+2*location]=1;
                break; 
                case '2':
                solstate[4+2*location]=1;
                solstate[8+2*location]=1;
                break; 
                case '3':
                solstate[4+2*location]=1;
                solstate[5+2*location]=1;
                break;
                case '4':
                solstate[4+2*location]=1;
                solstate[5+2*location]=1;
                solstate[9+2*location]=1;
                break;
                case '5':
                solstate[4+2*location]=1;
                solstate[9+2*location]=1;
                break;
                case '6':
                solstate[4+2*location]=1;
                solstate[5+2*location]=1;
                solstate[8+2*location]=1;
                break;
                case '7':     
                solstate[9+2*location]=1;
                solstate[8+2*location]=1;
                solstate[4+2*location]=1;
                solstate[5+2*location]=1;
                break;
                case '8':
                solstate[9+2*location]=1;
                solstate[8+2*location]=1;
                solstate[4+2*location]=1;
                break;
                case '9':
                solstate[8+2*location]=1;
                solstate[5+2*location]=1;
                break;      
                case '0':      
                solstate[5+2*location]=1;
                solstate[8+2*location]=1;
                solstate[9+2*location]=1;
                break;
                case '!':
                solstate[9+2*location]=1;
                solstate[9+2*location]=1;
                solstate[9+2*location]=1;
                solstate[9+2*location]=1;
                break;
                case '"':
                solstate[5+2*location]=1;
                break;
                case '#':
                solstate[1+2*location]=1;
                solstate[5+2*location]=1;
                solstate[9+2*location]=1;
                solstate[8+2*location]=1;
                break;
                case '$':
                solstate[0+2*location]=1;
                solstate[1+2*location]=1;
                solstate[4+2*location]=1;
                solstate[9+2*location]=1;
                break;
                case '%':
                solstate[1+2*location]=1;
                solstate[0+2*location]=1;
                solstate[9+2*location]=1;
                break;
                case '&':
                solstate[0+2*location]=1;
                solstate[1+2*location]=1;
                solstate[4+2*location]=1;
                solstate[9+2*location]=1;
                solstate[8+2*location]=1;
                break;
                case '\'':
                solstate[8+2*location]=1;
                break;
                case '(':
                solstate[0+2*location]=1;
                solstate[5+2*location]=1;
                solstate[4+2*location]=1;
                solstate[9+2*location]=1;
                solstate[8+2*location]=1;
                break;
                 case ')':
                solstate[5+2*location]=1;
                solstate[1+2*location]=1;
                solstate[4+2*location]=1;
                solstate[9+2*location]=1;
                solstate[8+2*location]=1;
                break;
                 case '*':
                solstate[0+2*location]=1;
                solstate[9+2*location]=1;
                break;
                 case '+':
                solstate[1+2*location]=1;
                solstate[8+2*location]=1;
                solstate[9+2*location]=1;
                break;
                case ',':
                solstate[9+2*location]=1;
                break;
                case '-':
                solstate[9+2*location]=1;
                solstate[8+2*location]=1;
                break;
                case '.':
                solstate[1+2*location]=1;
                solstate[9+2*location]=1;
                break;
                case '/':
                solstate[1+2*location]=1;
                solstate[8+2*location]=1;
                break;
                case '@':
                solstate[1+2*location]=1;
                break;
                case '[':
                solstate[1+2*location]=1;
                solstate[4+2*location]=1;
                solstate[9+2*location]=1;
                break;
                case '\\':
                solstate[0+2*location]=1;
                solstate[4+2*location]=1;
                solstate[5+2*location]=1;
                solstate[9+2*location]=1;
                break;
               
                
                case ']':
                solstate[0+2*location]=1;
                solstate[1+2*location]=1;
                solstate[4+2*location]=1;
                solstate[9+2*location]=1;
                solstate[5+2*location]=1;
                break;
               
                case '^':
                solstate[1+2*location]=1;
                solstate[5+2*location]=1;
                break;
                
                case '~':
                solstate[0+2*location]=1;
                solstate[1+2*location]=1;
                solstate[4+2*location]=1;
                solstate[5+2*location]=1;
                solstate[8+2*location]=1;
                solstate[9+2*location]=1;   
                break; 
                case '_':
                solstate[1+2*location]=1;
                solstate[5+2*location]=1;
                solstate[9+2*location]=1;
                break;
               
                default:
                solstate[0]=0;
                solstate[1]=0;
                solstate[3]=0;
                solstate[4]=0;
                solstate[5]=0;
                solstate[6]=0;
                solstate[7]=0;
                solstate[8]=0;
                solstate[9]=0;
                solstate[10]=0;
                solstate[11]=0;
                break;
                  
           }
 }
         
void printbr(int time){

              // P0 turn
              digitalWrite(P0, HIGH);
              if(solstate[0]==1){ digitalWrite(N0, HIGH); } 
              if(solstate[5]==1){ digitalWrite(N1, HIGH); }
              if(solstate[8]==1){ digitalWrite(N2, HIGH); }
             
              delayMicroseconds(time);
              digitalWrite(N0, LOW);   
              digitalWrite(N2, LOW);  
              digitalWrite(P0, LOW);   
              digitalWrite(N1, LOW);   
             
              // P2 turn
              digitalWrite(P2, HIGH);
             
              if(solstate[2]==1){ digitalWrite(N0, HIGH); } 
              if(solstate[7]==1){ digitalWrite(N1, HIGH); }
              if(solstate[10]==1) { digitalWrite(N2, HIGH); }
              
              delayMicroseconds(time*1.0);
              digitalWrite(N0, LOW);   
              digitalWrite(N2, LOW);  
              digitalWrite(P2, LOW);   
              digitalWrite(N1, LOW);   
              
             // P1 turn
              digitalWrite(P1, HIGH);
             
              if(solstate[1]==1){ digitalWrite(N0, HIGH); } 
              if(solstate[4]==1){ digitalWrite(N1, HIGH); }
              if(solstate[9]==1){ digitalWrite(N2, HIGH); }
              
              delayMicroseconds(time);
              digitalWrite(N0, LOW);   
              digitalWrite(N2, LOW);  
              digitalWrite(P1, LOW);   
              digitalWrite(N1, LOW);  

              // P3 turn
              digitalWrite(P3, HIGH);
             
              if(solstate[3]==1){ digitalWrite(N0, HIGH); } 
              if(solstate[6]==1){ digitalWrite(N1, HIGH); }
              if(solstate[11]==1){ digitalWrite(N2, HIGH); }
              
              delayMicroseconds(time*1.0);
              digitalWrite(N0, LOW);   
              digitalWrite(N2, LOW);  
              digitalWrite(P3, LOW);   
              digitalWrite(N1, LOW);  
              
              //P4/5/6/7 turn
           //   delayMicroseconds(time*4);

} 
           
void establishContact() {
           button1State = digitalRead(Button1);
           button2State = digitalRead(Button2);
           while ((Serial.available() <= 0) && ((button1State==HIGH) && (button2State == HIGH)))  {
              Serial.println("Ready");   // send an initial string
              button1State = digitalRead(Button1);
              button2State = digitalRead(Button2);
              delay(300);
            }
      }
           
void button_process() 
{
           button1State = digitalRead(Button1);
           button2State = digitalRead(Button2);
           
           // Forward button
          if(button1State==LOW){
                tone(12,1000,200);
                do {
                      button1State = digitalRead(Button1);
                }while(button1State == LOW);

                if((book_pointer < 149) && (book_mode==1) ) book_pointer = book_pointer + 2;
                
               if(book_mode ==0) { 
                   book_mode = 1;
//                  Serial.println("BookMode On");  
               }

//                Serial.println(text[book_pointer]);
//                Serial.println(text[book_pointer+1]);
            }
             
            // Backward button
            if(button2State==LOW){
                tone(12,1000,200);
                delay(300);  
                tone(12,1000,200);
                delay(300);  
                do {
                     button2State = digitalRead(Button2);
                }while(button2State == LOW);
                book_mode = 1;


                if((book_pointer >= 2) && (book_mode == 1))  book_pointer = book_pointer - 2;
                
                if(book_mode ==0) { 
                   book_mode = 1;
//                  Serial.println("BookMode On");  
               }
//                Serial.println(text[book_pointer]);
//                Serial.println(text[book_pointer+1]);
           }
}
