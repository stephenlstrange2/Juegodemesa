#include <iostream>
#include <chrono>
#include <thread>

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
            for (int i = 0; i < rand()%40; i++)
            {
            std::cout << "    _______\n  /\\       \\\n /  \\       \\\n/    \\_______\\\n\\    /       /\n \\  /       /\n  \\/_____  /\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(i*30));
            system("clear");
            std::cout << "    _______\n  /\\       \\\n /  \\   ()  \\\n/ () \\_______\\\n\\    /       /\n \\  /   ()  /\n  \\/_______/\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(i*30));
            system("clear");
            std::cout << "    _______\n  /\\ ()    \\\n /()\\       \\\n/    \\_____()\\\n\\    /()     /\n \\()/       /\n  \\/_____()/\n";      
            std::this_thread::sleep_for(std::chrono::milliseconds(i*30));
            system("clear");
            }
        }
    public:
        int tirarDados(int canttiros){
            if (canttiros <=  0 || canttiros > 6) return -1;
            dados = 0;
            int estado[] = {0,1,2};
            for (int i = 0; i < canttiros; i++)
            {
                int _estado = estado[rand()%3];
                std::cout<< eformat <<"TIRANDO DADOS";
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
//         void nuevoJugador(){
//             nombre = strNombre;
//             direccion = strDireccion;
//             placa = strPlaca;
//             fecha = strFecha;
//         }

//     // Setter
//         void setNombre(string strNombre){
//             nombre = strNombre;
//         }        
//         void setDireccion(string strDireccion){
//             direccion = strDireccion;
//         }
//         void setPlaca(string strPlaca){
//             placa = strPlaca;
//         }
//         void setFecha(string strFecha){
//             fecha = strFecha;
//         }

    // Getter
//         string getNombre(){
//             return nombre;
//         }        
//         string getDireccion(){
//             return direccion;
//         }
//         string getPlaca(){
//             return placa;
//         }
//         string getFecha(){
//             return fecha;
//         }
//         string getAll(){
//             string buffer = "";
//             buffer+= "Nombre: "+nombre+" Direccion: "+direccion;
//             buffer+= " Placa: "+placa+" Fecha de inicio de residencia: "+fecha+"\n"; 
//             return buffer;
//         }
};

