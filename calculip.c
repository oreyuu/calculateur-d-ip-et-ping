#include <stdio.h>
#include <stdlib.h>  // pour system()

void ipimage();
int ip_calculator();
int ping8888();
int exitcode();
int o1 ,o2, o3, o4; //ip adress
int cidr; //cidr
int tool = 0;

void ipimage() {

    printf("\033[31m");
    printf("░▒▓█▓▒░▒▓███████▓▒░        ░▒▓██████▓▒░░▒▓███████▓▒░░▒▓███████▓▒░░▒▓███████▓▒░░▒▓████████▓▒░░▒▓███████▓▒░▒▓███████▓▒░ \n");
    printf("░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░     ░▒▓█▓▒░        \n");
    printf("░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░     ░▒▓█▓▒░        \n");
    printf("░▒▓█▓▒░▒▓███████▓▒░       ░▒▓████████▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓███████▓▒░░▒▓██████▓▒░  ░▒▓██████▓▒░░▒▓██████▓▒░  \n");
    printf("░▒▓█▓▒░▒▓█▓▒░             ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░             ░▒▓█▓▒░     ░▒▓█▓▒░ \n");
    printf("░▒▓█▓▒░▒▓█▓▒░             ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░             ░▒▓█▓▒░     ░▒▓█▓▒░ \n");
    printf("░▒▓█▓▒░▒▓█▓▒░             ░▒▓█▓▒░░▒▓█▓▒░▒▓███████▓▒░░▒▓███████▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓████████▓▒░▒▓███████▓▒░▒▓███████▓▒░ \n");
    printf("\033[0m");
    printf("open source programme by oreyuu");
}

int main(void) {

    ipimage();
    
    while (1) {
    
    // prise en charge des variables : IP + CIDR


    printf("\nVous ete dans un outils conssu pour calculer les @IP sur un reseau local, et ping vers le 8.8.8.8 (dns de google) pour tester votre connexion\n");

    printf("\n[1] Calculateur d'@IP\n[2] Test de connexion\n[3] exit code\n> ");
    scanf("%d", &tool);


    switch ( tool ) {
        case 1 :
            ip_calculator();
            break;
        case 2 :
            ping8888();
            break;
        case 3 :
            exitcode();
            break;
        default :
            printf("mauvaise saisi");
            break;
    }
}

}

int ip_calculator() {

	printf("\n\nsaisissez votre @IP      : ");
	scanf("%d.%d.%d.%d", &o1, &o2, &o3, &o4);

	printf("saisissez votre CIDR     : ");
	scanf("%d",&cidr);

    
    
    //Verification des Variables

		if (cidr < 0 || cidr > 32) { //CIDR
		
			printf("mauvaise saisi, veuiller entrez un CIDR valide.");

			return 1;
		}
		if ( //octes des @IP 

			o1 < 0 || o1 > 255 || o2 < 0 || o2 > 255 || o3 < 0 || o3 > 255 || o4 < 0 || o4 > 255

		) {
			printf("mauvais @IP, veuillez entre une @IP valide");

			return 1;
		}
		 unsigned int masque = 0xFFFFFFFF << (32 - cidr);

    //afichage des information saisi
    


    printf("\nAdresse saissi           : %d.%d.%d.%d\n",o1,o2,o3,o4);
    printf("votre CIDR               : /%d\n",cidr);
    
         //Calcul de masque de sous réseau 


           // Affiche le masque en binaire (avec points toutes les 8 bits)
    printf("Masque en binaire        : ");
    for (int i = 0; i < 32; i++) {
        if (i < cidr)
            printf("1");
        else
            printf("0");

         if ((i + 1) % 8 == 0 && i != 31)
            printf(".");
    }
    printf("\n");

    // Affiche le masque en décimal pointé
    printf("Masque en décimal pointé : %u.%u.%u.%u\n",
        (masque >> 24) & 0xFF,
        (masque >> 16) & 0xFF,
        (masque >> 8) & 0xFF,
        masque & 0xFF
    );

        // Calcul de l'adresse réseau
    unsigned int ip = (o1 << 24) | (o2 << 16) | (o3 << 8) | o4;
    unsigned int reseau = ip & masque;

    printf("Adresse réseau           : %u.%u.%u.%u\n",
        (reseau >> 24) & 0xFF,
        (reseau >> 16) & 0xFF,
        (reseau >> 8) & 0xFF,
        reseau & 0xFF
    );

    // Calcul du nombre d'adresses IP utilisables
    int nb_ips_utilisables = 0;

    if (cidr < 31) {
        nb_ips_utilisables = (1 << (32 - cidr)) - 2;
    } else if (cidr == 31) {
        nb_ips_utilisables = 2; // point à point
    } else {
        nb_ips_utilisables = 1; // /32 : une seule IP
    }

    printf("Nombre d'IP utilisables  : %d\n", nb_ips_utilisables);

     unsigned int broadcast = ip | ~masque;

    printf("Adresse de diffusion     : %u.%u.%u.%u\n",
        (broadcast >> 24) & 0xFF,
        (broadcast >> 16) & 0xFF,
        (broadcast >> 8) & 0xFF,
        broadcast & 0xFF
    );

    return 0;
}

int ping8888() {

    int choix = 0;
    int oo1, oo2, oo3, oo4; //ip pour la fonction case choix deux 
    printf("[1] ping le dns de google   [2] ping un adress ip au choix\n>");
    scanf("%d", &choix);

    switch ( choix ) {
        case 1 :
            system("ping -c 4 8.8.8.8");
            break;
        case 2 :
            char commande[100];

            printf("veuillez saisire l'ip que vous shoutez ping\n>");
            scanf("%d.%d.%d.%d", &oo1, &oo2, &oo3, &oo4);
            
            sprintf(commande, "ping -c 4 %d.%d.%d.%d", oo1, oo2, oo3, oo4);
            system(commande);
            break; 
        default :
            printf("mauvaise saisi");
            break;
    }    
    

    return 0;
}

int exitcode() {

    printf("bye bye !");
    exit(0);
}

