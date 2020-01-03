#ifndef __IGVINTERFAZ
#define __IGVINTERFAZ

#if defined(__APPLE__) && defined(__MACH__)
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#endif

#include <string>

#include "igvEscena3D.h"
#include "igvCamara.h"
#include "WorldManager.h"
#include "SelectionController.h"

using namespace std;

typedef enum {
	IGV_VISUALIZAR,
	IGV_SELECCIONAR,
} modoInterfaz;

class igvInterfaz {
	protected:
		// Atributos
		int ancho_ventana; // ancho inicial de la ventana de visualizacion
		int alto_ventana;  // alto inicial de la ventana de visualizacion

		modoInterfaz modo; // IGV_VISUALIZAR: en la ventana se va a visualizar de manera normal la escena, 
						   // IGV_SELECCIONAR: se ha pulsado sobre la ventana de visualización, la escena se debe
					       // visualizar en modo selección

		GLfloat pixel[3];

		int cursorX, cursorY; // pixel de la pantalla sobre el que está situado el ratón, por pulsar o arrastrar

		//-------------------------------------------------------------------CAMARA
		igvPunto3D initialEye = igvPunto3D(20.0, 20.0, 20.0);
		igvPunto3D initialDirection = igvPunto3D(7.0, 8.0, 0.0);
		igvPunto3D initialUp = igvPunto3D(0.0, 1.0, 0.0);

		float oldFormat = 0;
		float newFormat = 0;
		//-------------------------------------------------------------------FIN CAMARA

		igvEscena3D escena; // escena que se visualiza en la ventana definida por igvInterfaz
		igvCamara camara; // cámara que se utiliza para visualizar la escena
		WorldManager* worldManager; //se encarga de gestionar el mundo de juego
		SelectionController selectionController; //se encargar de gestionar las selecciones

	public:
		// Constructores por defecto y destructor
		igvInterfaz();
		~igvInterfaz();

		float oldMouseX;
		float oldMouseY;
		float mouseX;
		float mouseY;

		bool leftClick;
		bool rightClick;

		// Metodos estáticos
		// callbacks de eventos
		static void set_glutKeyboardFunc(unsigned char key, int x, int y); // metodo para control de eventos del teclado
		static void set_glutReshapeFunc(int w, int h); // método que define la camara de vision y el viewport
		                                               // se llama automáticamente cuano se camba el tamaño de la ventana
		static void set_glutDisplayFunc(); // método para visualizar la escena

		static void  set_glutMouseFunc(GLint boton, GLint estado, GLint x, GLint y); // control de pulsacion del raton
		static void  set_glutMotionFunc(GLint x, GLint y); // control del desplazamiento del raton con boton pulsado

		// Metodos
		// crea el mundo que se visualiza en la ventana
		void crear_mundo(void);

		// inicializa todos los parámetros para crear una ventana de visualización
		void configura_entorno(int argc, char** argv, // parametros del main
			                     int _ancho_ventana, int _alto_ventana, // ancho y alto de la ventana de visualización
			                     int _pos_X, int _pos_Y, // posicion inicial de la ventana de visualización
													 string _titulo // título de la ventan de visualización
													 );
		void inicializa_callbacks(); // inicializa todas los callbacks

		void inicia_bucle_visualizacion(); // visualiza la escena y espera a eventos sobre la interfaz

		// métodos get_ y set_ de acceso a los atributos
		int get_ancho_ventana(){return ancho_ventana;};
		int get_alto_ventana(){return alto_ventana;};

		void set_ancho_ventana(int _ancho_ventana){ancho_ventana = _ancho_ventana;};
		void set_alto_ventana(int _alto_ventana){alto_ventana = _alto_ventana;};

		// actual vector representing the camera's direction
		float LX = 0.0f, lz = -1.0f;
		// XZ position of the camera
		float xx = 0.0f;
		float z = 5.0f;
};

#endif
