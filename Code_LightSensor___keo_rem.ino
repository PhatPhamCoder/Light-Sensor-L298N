int in3=6;//Nối chân in3 L298N với D6 Arduino
int in4=7;//Nối chân in4 L298N với D7 Arduino
int go=8;//Nút mở rèm cửa
int back=9;//Nút đóng rèm cửa
int left=11;//Dây Mass để khi rèm của chạy đến chạm vô dây này sẽ dừng động cơ
int right=12;
void setup() {
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(go, INPUT_PULLUP);//Khai báo nút bấm
  pinMode(back, INPUT_PULLUP);
  pinMode(left, INPUT);
  pinMode(right, INPUT);
}

void loop() {
  int cbas=digitalRead(10);//Sử dụng châm Digital của cảm biến. Gắn D0 cbas với chân 10 của Arduino
  int trangthainut1=digitalRead(left);
  int trangthainut2=digitalRead(right); 
  int trangthaimo=digitalRead(go);
  int trangthaidong=digitalRead(back);
  if(cbas==0){//Có ánh sáng
    if(trangthaidong==0 && trangthaimo!=0 && trangthainut2!=1){
      mo();
      }
      else if(trangthaidong!=0 && trangthaimo==0 && trangthainut1!=1){
        dong();
        }
        else {dung();}
  }
  else{//Không có ánh sáng
    if(trangthainut1!=1){
      dong();
      }
      else {dung();}
      }
}
void mo(){//hàm mở cửa
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}
void dong(){//hàm đóng cửa
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}
void dung(){//hàm dừng moto
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}
