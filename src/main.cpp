/*
Primero llamamos a las librerias y headers de cajon
*/
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include <cstdio>
#include <ctime>
#include <random>
using namespace std;
const char *eformat = "                                             ";
#include "str.h"

#include <stdio.h>

cuarto cuartos[6];
itemCard items[6];
eventCard eventos[6];
omenCard presagios[6];


specsJugadores jugador;
int buffer;
void inicializar(){
    cuartos[0].nuevoCuarto("Atico",false,false,true,true,false,false,2,"When exiting, you must attempt a Speed roll of 3+. if you fail, lose 1 Might (but continue moving).");
    cuartos[1].nuevoCuarto("Balcon",false,false,true,false,true,false,2);
    cuartos[2].nuevoCuarto("Cripta",true,false,false,true,false,false,1,"If you end your turn here, take 1 point of mental damage.");
    cuartos[3].nuevoCuarto("Jardines",false,true,false,true,false,false,2);
    cuartos[4].nuevoCuarto("Biblioteca",false,true,true,true,false,false,2,"If you endo your turn here gain 1 knowledge.");
    cuartos[5].nuevoCuarto("Gimnasio",true,false,true,false,true,false,2,"If you end your turn here gain 1 speed");
    items[0].itemNuevo("Chest","This antique chest has seen better days.","No one gets this Omen card\nPlace the Chest token in this room.\nAny exporer in this room rolls 1 additional die when making skill checks.\nMake a haunt roll now.");
    items[1].itemNuevo("Letter","The words seem to jump off the page at you... lie magic.","Gain 1 Knowledge now. Lose 1 Knowledge if you lose the letter.\n This omen can't be dropped, traded, or stolen.\nMake a haunt roll now.");
    items[2].itemNuevo("Boy","COMPANION\nPlucky kid. How did he get in here?","Gain 2 Speed now. Lose 2 Speed if you lose custody of the Boy.\nThis omen can't be dropped, traded, or stolen.\nMake a haunt roll now.");
    items[3].itemNuevo("Burglar","COMPANION\nThis dude picked the worng house.","Gain 1 Might now. Lose 1 Might if you lose custody of the Burglar.\nTake possession of the PICKPOCKET'S GLOVES item from another player. If this card is not in play, look through the item pile, and take the card.\nThen shuffle the item pile.\nThis omen can't be dropped, traded, or stolen.\nMake a haunt roll now.");
    items[4].itemNuevo("GHOST NURSE","COMPANION\nShe doesn't seem to realize that she's dead, but she looks helpful enough.","Gain 2 Knowledge and lose 1 Sanity now. Lose 2 Knowledge and gain 1 Sanity if you lose custody of the Ghost Nurse.\nTake possession of the HEALING SALVE Item from another player. If this card is not in play, look through the item pile, and take it. Then shuffel the item pile. This omen can't be dropped, traded, or stolen.\nMake a haunt roll now.");
    items[5].itemNuevo("Butler","COMPANION\nHe's definitely creepy enough to work here.","Gain 1 Knowledge and 1 Speed now. Lose 1 Knowledge and 1 Speed if you lose custody of the Butler.\nTake possession of the MAP item from another player. If this card is not in play, look through the item pile, and take the MAP. Then shuffle the item pile. This omen can't be dropped, traded, or stolen.nMake a haunt roll now.");
    presagios[0].omeNuevo("MONKEY'S PAW","This svered paw is attached to a chain like a good luck charm.","Once during each turn, you can use the Monkeys Paw to reroll any number of dice in one skill check. You must keep the new rolls.\nAfter you decide the outcome of the new roll, roll 2 dice.\n1+ Nothing Happens\n0 Lose 1 point in your three highest traits.");
    presagios[1].omeNuevo("STRANGE STONE NECKLACE","A tranished yellow stone pulses on the necklace.","Discar this card to automatically succeed on one event card skill check witch the highest numbered roll possible on the card.");
    presagios[2].omeNuevo("SACRED URN","Asges from a long dead wizard (or so the plaque on the Urn says)","Discard this card to sprinkle the protective ashes in a circle around yourself. You receive a bonus of 2 extra defensive die if you are attacked before your next turn.");
    presagios[3].omeNuevo("VIAL OF RED LIQUID","A thick gooey liquid in a corked vial","Discard this card for 3 extra movement for 1 turn.\nThis cannot be used if you are carrying anything heavy that reduces movement.");
    presagios[4].omeNuevo("LANTERN","Surprisingly, this dusty old lantern is still filled with oil.","Gain 1 Knowledge and 1 sanity now.\nLose 1 Knowledge and 1 Sanity if you lose the Lantern.");
    presagios[5].omeNuevo("POSSESSED IDOL","This statuette occasionally seems to shift on its own.","Once during each turn, you may roll 2 dice\n4 Raise your weakes trait by 1 point.\n1-3 Nothing happens.\n0 Lower your strongest trait by 1 point.");
    eventos[0].eventoNuevo("BZZZZZZ","As yo peer around the room,you see a bee hive.You carefully step closer to see it's held up by... NOTHING\nThe hive suddenly drops to the ground and a swarm of bees angrily escapes.","You and any explorer in the same room or an adjacent room must attempt a Sanity roll.\n6+ You calmly stand still and wait for the bees to disperse Gain 1 Sanity\n4-5 You inch away from the bees, and leave with only a few bites.\n0-3 The bees smell your fear as you try to dash away. They swarm you as you run, then quickly return to ther hive.\nTake 1 die of physical damage and move your explorer into an adjacent, explored room.");
    eventos[1].eventoNuevo("SPECTRE","A ghost approaches and asks you a riddle...","Make a Knowledge roll to answer:\n5+ Rigth! The spectre rewards you.\nDraw an item card.\n0-4 Wrong! The spectre curses you.\nTake one die of mental damage.");
    eventos[2].eventoNuevo("LOOK OUT!","You hear a faint 'Click'.\nTurning 'round, you see an axe, once suspended on the ceilling, now dislodged and swinging towards you.","You must attempt a Speed roll.\nAn explorer in the Junk Room rolls one fewer die.\n5+ You roll out of the way.\nGain 1 Speed\n4+ You dive out of the way.\n2-3 The axe catches your feet.\nloose 1 Speed.\n0 The axe takes a chunk out of you.\nTake 2 dice of physical damage.");
    eventos[3].eventoNuevo("BE MINE","A young woman and man stand in the room, wrapped in each othe's embrace.\nYou turn away, wanting to give them their privacy...until you realize the sounds you are hearing sound more like muffled screams.","You look at the couple, and wretch at the sight of their faces.\nWhen at first you thought they were only kissing, their very faces hace in fact been fused together...\nAnd the sickening image fades from view.\nTake 2 dice of mental damage.\nIf you hace the Medical Kit in your possession, take 3 dice instead.");
    eventos[4].eventoNuevo("MACABRE REFLECTION","You jump in fright as the full length vanity mirror reveals whats you look like at the moment of your death.","You must attempt a Sanity roll:\n4+ You blink your eyes and the image is gone.\nGain 1 Sanity.\n1-3 You shudder and avert your gaze.\nLose 1 Sanity.\n0 You shriek in abject terror.\nTake 1 die of mental damage.");
    eventos[5].eventoNuevo("HAUNTED PORTRAITS", "The Portrairs on the walls seem to have a life on their own as you pass by, one of them begins to talk...","You must attempt a Sanity roll:\n4+ It tells you secrets about the house.\nGain 1 Knowledge.\n1-3 It screa, and you chill to the bone.\nLose 1 Sanity.\n0 It tells you grim details of your death.\nTake 1 die of mental damage.");
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0,5);
    int semilla = dist6(rng);
    srand(semilla);
}

void pintarMenu(){
    int flag = 1;
    do
    {
        system("clear");
        std::cout << eformat << "MENU\n\n"<< eformat <<"1.Iniciar Juego\n"<<eformat<<"2.Salir\n";
        std::cin >> buffer;
        if(buffer==1){
            system("clear");
            std::cout << eformat << "Elige a tu jugador\n\n"<< eformat <<"1.Brandon Jaspers\n"<<eformat<<"2.Zoe Ingstrom\n"<< eformat <<"3.Father Rhinohardt\n"<<eformat<<"4.Salir al menu anterior\n";
            std::cin >> buffer;
            switch (buffer)
            {
            case 1:
                std::cout << "Brandon Jaspers\n";
                jugador.nuevoJugador(1);
                flag = 0;
                break;
            
            case 2:
                std::cout << "Zoe Ingstrom";
                jugador.nuevoJugador(2);
                flag = 0;
                /* code */
                break;
            case 3:
                std::cout << "Father Rhinohardt";
                jugador.nuevoJugador(3);
                flag = 0;
                /* code */
                break;
            default:
            std::cout << "Respuesta no valida.\n";
                break;
            }
        }
    } while (flag);
}

void jugar(){
    int op;
    int flag = 1;
    int turnodados;
    int puntos;
    int cuar;
    system("clear");
    std::cout << std::boolalpha;
    do
    {
        std::cout <<"\n" << eformat << "MENU DEL JUEGO \n\n"<< eformat <<"1.Sacar carta cuarto\n"<<eformat<<"2.Tirar dados\n"<< eformat <<"3.Declarar puntos\n"<<eformat<<"4.Salir\n";
        std::cin >> op;
        switch (op)
        {
            case 1:
                cuar = cuartos[random()%6].leer();
                sleep(10);
                switch (cuar)
                {
                    case 1:
                        presagios[random()%6].leer();
                        break;
                    
                    case 2:
                        eventos[random()%6].leer();
                        break;

                    case 3:
                        items[random()%6].leer();
                        break;
                    default:
                        break;
                }
                break;

            case 2:
                std::cout << eformat << "Cuantos dados quieres tirar? (1-6)";
                std::cin >> turnodados; 
                jugador.tirarDados(turnodados);
                sleep(5);
                break;
            
            case 3:
                jugador.leerPuntos();
                std::cout << eformat <<"Declarar puntos de velocidad\n";
                std::cin >> puntos;
                if (puntos >= 10){
                    std::cout << "GANASTE MUCHAS GRACIAS POR JUGAR";
                    sleep(3);
                    return;
                }
                if (puntos <= 0){
                    std::cout << "PERDISTE GRACIAS POR JUGAR";
                    sleep(3);
                    return;
                }
                jugador.declararVelocidad(puntos);

                std::cout << eformat <<"Declarar puntos de poder\n";
                std::cin >> puntos;
                if (puntos >= 10){
                    std::cout << "GANASTE MUCHAS GRACIAS POR JUGAR";
                    sleep(3);
                    return;
                }
                if (puntos <= 0){
                    std::cout << "PERDISTE GRACIAS POR JUGAR";
                    sleep(3);
                    return;
                }
                jugador.declararPoder(puntos);

                std::cout << eformat <<"Declarar puntos de cordura\n";
                std::cin >> puntos;
                if (puntos >= 10){
                    std::cout << "GANASTE MUCHAS GRACIAS POR JUGAR";
                    sleep(3);
                    return;
                }
                if (puntos <= 0){
                    std::cout << "PERDISTE GRACIAS POR JUGAR";
                    sleep(3);
                    return;
                }
                jugador.declararCordura(puntos);

                std::cout << eformat <<"Declarar puntos de conocimiento\n";
                std::cin >> puntos;
                if (puntos >= 10){
                    std::cout << "GANASTE MUCHAS GRACIAS POR JUGAR";
                    sleep(3);
                    return;
                }
                if (puntos <= 0){
                    std::cout << "PERDISTE GRACIAS POR JUGAR";
                    sleep(3);
                    return;
                }
                jugador.declararConocimiento(puntos);

                std::cout << eformat << "Excelente los specs del jugador quedaron del siguiente modo\n";
                jugador.leerPuntos();
                break;
            
            default:
                break;
        }
    } while (flag);
    
}

int main(){
    inicializar();
    pintarMenu();
    jugar();
    return 0;

}