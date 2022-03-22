#include <iostream>
#include <chrono>
#include <thread>

class omenCard{


    public:
        string subtitle;
        string text;
        string name;
        void omeNuevo(string _name, string _subtitle, string _text){
            name = _name;
            subtitle = _subtitle;
            text = _text;
        }
        void leer(){
            std::cout << name;
            std::cout << "\n";
            std::cout << subtitle << "\n";
            std::cout << text << "\n";
        }
};


class itemCard{

    public:
        string name;
        string subtitle;
        string text;
        void itemNuevo(string _name, string _subtitle, string _text){
            name = _name;
            subtitle = _subtitle;
            text = _text;
        }
        void leer(){
            std::cout << name;
            std::cout << "\n";
            std::cout << subtitle << "\n";
            std::cout << text << "\n";
        }
};

class eventCard{


    public:
        string name;
        string subtitle;
        string text;
        void eventoNuevo(string _name, string _subtitle, string _text){
            name = _name;
            subtitle = _subtitle;
            text = _text;
        }
        void leer(){
            std::cout << name;
            std::cout << "\n";
            std::cout << subtitle << "\n";
            std::cout << text << "\n";
        }
};

class cuarto{
    private:
        string roomName;
        bool basement;
        bool ground;
        bool upper;
        bool omen;
        bool event;
        bool item;
        int puertas;
        string text;

    public:
        void nuevoCuarto(string _name, bool _b,bool _g,bool _u,bool _e,bool _o,bool _i,int _d,string _texto =""){
            roomName = _name;
            basement= _b;
            ground = _g;
            upper = _u;
            omen = _o;
            event = _e;
            item = _i;
            puertas = _d;
            text = _texto;

        }

        int leer(){
            std::cout << roomName << "\nSotano ? " << basement << "\nPlanta Baja ? "
                      << ground << "\nPlanta Alta ? " << upper << "\nPresagio ? "<< omen 
                      << "\nEvento ? "<< event << "\nArticulo ? " << item << "\nTiene "
                      << puertas << " puertas\n";
            std::cout << text << "\n";
            if (omen) return 1;
            if (event) return 2;
            return 3;
        }

};

class specsJugadores{
    private:
        string nombre;
        int aFvelocidad;
        int aFpoder;
        int aMcordura;
        int aMconocimiento;
        int turno;
        int danoRecibido;
        int salud;
        int dados;
        void animacionDados(){
            system("clear");
            for (int i = 0; i < rand()%40; i++)
            {
                std::cout<< "TIRANDO DADOS\n";
                std::cout << "    _______\n  /\\       \\\n /  \\       \\\n/    \\_______\\\n\\    /       /\n \\  /       /\n  \\/_____  /\n";
                std::this_thread::sleep_for(std::chrono::milliseconds(i*30));
                system("clear");
                std::cout<< "TIRANDO DADOS\n";
                std::cout << "    _______\n  /\\       \\\n /  \\   ()  \\\n/ () \\_______\\\n\\    /       /\n \\  /   ()  /\n  \\/_______/\n";
                std::this_thread::sleep_for(std::chrono::milliseconds(i*30));
                system("clear");
                std::cout<< "TIRANDO DADOS\n";
                std::cout << "    _______\n  /\\ ()    \\\n /()\\       \\\n/    \\_____()\\\n\\    /()     /\n \\()/       /\n  \\/_____()/\n";      
                std::this_thread::sleep_for(std::chrono::milliseconds(i*30));
                system("clear");
            }
        }
    public:
        int tirarDados(int canttiros){
            if (canttiros <=  0 || canttiros > 6) {
                std::cout << "NO SE PUEDE JUGAR ESA CANTIDAD DE DADOS";
                return -1;
            }
            dados = 0;
            int estado[] = {0,1,2};
            for (int i = 0; i < canttiros; i++)
            {
                int _estado = estado[rand()%3];
                sleep(3);
                animacionDados();
                std::cout << "Tu dado numero "<< i+1 <<" fue un \n";
                switch (_estado)
                {
                case 0:
                    std::cout << "    _______\n  /\\       \\\n /  \\       \\\n/    \\_______\\\n\\    /       /\n \\  /       /\n  \\/_____  /\n";
                    sleep(3);
                    break;
                case 1:
                    std::cout << "    _______\n  /\\       \\\n /  \\   ()  \\\n/ () \\_______\\\n\\    /       /\n \\  /   ()  /\n  \\/_______/\n";
                    dados++;
                    sleep(3);
                    break;
                case 2:
                    std::cout << "    _______\n  /\\ ()    \\\n /()\\       \\\n/    \\_____()\\\n\\    /()     /\n \\()/       /\n  \\/_____()/\n";
                    dados+=2;
                    sleep(3);
                    break;
                default:
                    std::cout<<"Error fatal, STD RAND NOT WORKING";
                    break;
                }
            }
            std::cout << "\nDADOS TIRADOS: "<< canttiros+1 <<"\nPuntos Acumulados: "<<dados << "\n"; 
            
        }
        int tomarCartaMapa(){
            return 1;
        } 
        bool maldicion(){
            return false;
        }
        void nuevoJugador(int player){
            switch (player)
            {
            case 1:
                nombre = "Brandon Jaspers";    /* code */
                aFvelocidad = 4;
                aFpoder = 4;
                aMconocimiento = 3;
                aMcordura = 4;
                break;
            
            case 2:
                nombre = "Zoe Ingstrom";    /* code */
                aFvelocidad = 4;
                aFpoder = 3;
                aMconocimiento = 3;
                aMcordura = 5;
                break;

            case 3:
                nombre = "Father Rhinohardt";    /* code */
                aFvelocidad = 3;
                aFpoder = 2;
                aMconocimiento = 4;
                aMcordura = 6;
                break;
            default:
                break;
            }
        }

        void leerPuntos(){
            std::cout << "\n Actualmente " << nombre << " tiene Fisicamente\n"
                      << "AF Velocidad    : " << aFvelocidad << "\n"
                      << "AF Poder        : " << aFpoder << "\nTiene mentalmente\n"
                      << "AM Cordura      : " << aMcordura << "\n"
                      << "AM Conocimiento : " << aMconocimiento << "\n";
        }
        void declararVelocidad(int _velocidad){
            aFvelocidad = _velocidad;
        }
        void declararPoder(int _poder){
            aFpoder = _poder;
        }
        void declararCordura(int _cordura){
            aMcordura = _cordura;
        }
        void declararConocimiento(int _conocimiento){
            aMconocimiento = _conocimiento;
        }


};

