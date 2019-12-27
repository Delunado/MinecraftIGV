#include "pch.h"
#include <cstdlib>
#include <stdio.h>
#include <iostream>

#include "igvInterfaz.h"


extern igvInterfaz interfaz; // los callbacks deben ser estaticos y se requiere este objeto para acceder desde
 // ellos a las variables de la clase

// Metodos constructores -----------------------------------


igvInterfaz::igvInterfaz() :worldManager(new WorldManager(5, 5, 5)), selectionController() {}
>>>>>>> Seleccion V1 (arreglar fallo al crear bloque)

igvInterfaz::~igvInterfaz() {}


// Metodos publicos ----------------------------------------

void igvInterfaz::crear_mundo(void) {
	// crear cámaras
	interfaz.camara.set(IGV_PERSPECTIVA, interfaz.igvNormal1, interfaz.igvNormal2, interfaz.igvNormal3,
		55, 1.3f, 0.01, 100);

	//Asignamos el SelectionController al WorldManager
	interfaz.worldManager->SetSelectionController(&selectionController);

	std::cout << "Iniciando el mundo" << std::endl;
	worldManager->InitWorld();
	std::cout << "Mundo iniciado" << std::endl;

	interfaz.oldFormat = interfaz.get_alto_ventana();

	//Asignamos el WorldManager a la Escena
	interfaz.escena.SetWorldManager(worldManager);
}

void igvInterfaz::configura_entorno(int argc, char** argv,
	int _ancho_ventana, int _alto_ventana,
	int _pos_X, int _pos_Y,
	string _titulo) {
	// inicialización de las variables de la interfaz																	
	ancho_ventana = _ancho_ventana;
	alto_ventana = _alto_ventana;

	// inicialización de la ventana de visualización
	glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
glutInitWindowSize(_ancho_ventana, _alto_ventana);
glutInitWindowPosition(_pos_X, _pos_Y);
	glutCreateWindow(_titulo.c_str());

	glEnable(GL_DEPTH_TEST); // activa el ocultamiento de superficies por z-buffer
glClearColor(1.0, 1.0, 1.0, 0.0); // establece el color de fondo de la ventana

	glEnable(GL_LIGHTING); // activa la iluminacion de la escena
glEnable(GL_NORMALIZE); // normaliza los vectores normales para calculo iluminacion

	glEnable(GL_TEXTURE_2D); // activa el uso de texturas

	crear_mundo(); // crea el mundo a visualizar en la ventana
}

void igvInterfaz::inicia_bucle_visualizacion() {
	glutMainLoop(); // inicia el bucle de visualizacion de OpenGL
}

void igvInterfaz::set_glutSpecialFunc(int key, int x, int y) {
	// Apartado F: manejo de las teclas especiales del teclado para mover la posición del foco

	glutPostRedisplay(); // renueva el contenido de la ventana de vision
}

void igvInterfaz::set_glutKeyboardFunc(unsigned char key, int x, int y) {
	switch (key) {

	case 'c':
		if (interfaz.camara.tipo != IGV_PERSPECTIVA) {

			interfaz.camara.set(IGV_PERSPECTIVA, interfaz.igvNormal1, interfaz.igvNormal2, interfaz.igvNormal3,
				55, 1.3f, 0.01, 100);
		}
		else {

			interfaz.camara.set(IGV_PARALELA, interfaz.igvNormal1, interfaz.igvNormal2, interfaz.igvNormal3,
				-1 * 3, 1 * 3, -1 * 3, 1 * 3, -1 * 3, 200);
		}

		interfaz.camara.aplicar();

		break;
	case 'x':
		interfaz.camara.cambiarDistanciaPlano(0.2);
		interfaz.camara.aplicar();
		break;
	case 'X':
		interfaz.camara.cambiarDistanciaPlano(-0.2);
		interfaz.camara.aplicar();
		break;
	case 'v':
		if (interfaz.newFormat == 0) {

			interfaz.newFormat = interfaz.get_ancho_ventana() * 9 / 16;
		}
		else {

			interfaz.newFormat = 0;
		}

		interfaz.set_glutDisplayFunc();
		break;

	case 'a':
			interfaz.camara.MoveRight(-1.0);
		break;
	case 'd':
			interfaz.camara.MoveRight(1.0);
		break;
	case 'w':
		interfaz.camara.MoveForward(1.0);

		break;
	case 's':
		interfaz.camara.MoveForward(-1.0);
		break;
	case 'q':
		interfaz.camara.MoveUp(1.0);
		break;
	case 'e':
		interfaz.camara.MoveUp(-1.0);
		break;
	case 'z':
		interfaz.camara.zoom(0.2f);
		break;
	case 'Z':
		interfaz.camara.zoom(-0.2f);
		break;

	case 'j': // activa/desactiva la visualizacion de los ejes
		interfaz.escena.set_ejes(interfaz.escena.get_ejes()?false:true);
	  	break;
    case 27: // tecla de escape para SALIR
    	exit(1);
    	break;
  }
	glutPostRedisplay(); // renueva el contenido de la ventana de vision
}

void igvInterfaz::set_glutReshapeFunc(int w, int h) {
  // dimensiona el viewport al nuevo ancho y alto de la ventana
  // guardamos valores nuevos de la ventana de visualizacion
	interfaz.set_ancho_ventana(w);
	interfaz.set_alto_ventana(h);

	// establece los parámetros de la cámara y de la proyección
	interfaz.camara.aplicar();
}

void igvInterfaz::set_glutDisplayFunc() {
	if (interfaz.modo == IGV_SELECCIONAR) {
		glDisable(GL_LIGHTING); //desactiva la iluminacion de la escena

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_CULL_FACE);

		interfaz.camara.aplicar();

		//Dibujamos los BV
		interfaz.worldManager->DrawWorldBV();

		//We obtain the clicked pixel
		glReadPixels(interfaz.cursorX, interfaz.alto_ventana - interfaz.cursorY, 1, 1, GL_RGB, GL_FLOAT, interfaz.pixel);

		//Aqui hay que comprobar objeto clickado y hacer cosas con el
		std::cout << "Pixel: " << interfaz.pixel[0] << ", " << interfaz.pixel[1] << ", " << interfaz.pixel[2] << std::endl;

		Bloque* auxBlock = interfaz.selectionController.GetBlock(interfaz.pixel);

		if (auxBlock != NULL)
			//interfaz.worldManager->EraseBlock(auxBlock);
			interfaz.worldManager->CreateBlock(auxBlock, interfaz.selectionController.GetPosition(interfaz.pixel), TEXTURES::STONE);

		interfaz.modo = IGV_VISUALIZAR;

		glEnable(GL_LIGHTING);
		glEnable(GL_TEXTURE_2D);
	}
	else {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // borra la ventana y el z-buffer

		// se establece el viewport
		if (interfaz.newFormat == 0) {
			interfaz.set_glutReshapeFunc(interfaz.get_ancho_ventana(), interfaz.oldFormat);
			glViewport(0, 0, interfaz.get_ancho_ventana(), interfaz.get_alto_ventana());
		}
		else {
			interfaz.set_glutReshapeFunc(interfaz.get_ancho_ventana(), interfaz.newFormat);
			glViewport(0, interfaz.get_ancho_ventana() / 16, interfaz.get_ancho_ventana(), interfaz.get_alto_ventana());
		}

		//visualiza la escena
		interfaz.escena.visualizar();

		//actualiza el mundo


		// refresca la ventana
		glutSwapBuffers(); // se utiliza, en vez de glFlush(), para evitar el parpadeo
	}
}

void igvInterfaz::set_glutMouseFunc(GLint boton, GLint estado, GLint x, GLint y) {
	// Apartado E: guardar que el boton se ha presionado o se ha soltado, si se ha pulsado hay que
	// pasar a modo IGV_SELECCIONAR
	if (boton == GLUT_LEFT_BUTTON) {
		if (estado == GLUT_DOWN) {
			interfaz.modo = IGV_SELECCIONAR;
		}
	}

	// Apartado E: guardar el pixel pulsado	
	interfaz.cursorX = x;
	interfaz.cursorY = y;

	// Apartado E: renovar el contenido de la ventana de vision 
	glutPostRedisplay();
}

void igvInterfaz::set_glutMotionFunc(GLint x, GLint y) {

	// Apartado F: si el botón está retenido y hay algún objeto seleccionado,
	// comprobar el objeto seleccionado y la posición del ratón y actualizar
	// convenientemente el grado de libertad del objeto correspondiente 

	// Apartado F: guardar la nueva posición del ratón 
	interfaz.cursorX = x;
	interfaz.cursorY = y;

	// Apartado F: renovar el contenido de la ventana de vision 
	glutPostRedisplay();
}


void igvInterfaz::set_glutMouseFunc(GLint boton, GLint estado, GLint x, GLint y) {
	// Apartado E: guardar el pixel pulsado
	interfaz.cursorX = x;
	interfaz.cursorY = y;

	// Apartado E: renovar el contenido de la ventana de vision 
	glutPostRedisplay();
}


void igvInterfaz::set_glutMotionFunc(GLint x, GLint y) {

	interfaz.oldMouseX = interfaz.mouseX;
	interfaz.oldMouseY = interfaz.mouseY;
	interfaz.mouseX = x;
	interfaz.mouseY = y;
	
	//Mov Camara eje X
	if ((interfaz.mouseX - interfaz.oldMouseX) >= 0)
	{
		interfaz.camara.RotateRight(2.0);
	}
	else if ((interfaz.mouseX - interfaz.oldMouseX) < 0) 
	{
		interfaz.camara.RotateLeft(2.0);
	}

	if (interfaz.mouseX > interfaz.ancho_ventana - 50) {
		glutWarpPointer(interfaz.ancho_ventana / 2, interfaz.alto_ventana / 2);
	}
	if (interfaz.mouseX < 50) {
		glutWarpPointer(interfaz.ancho_ventana / 2, interfaz.alto_ventana / 2);
	}

	////Mov Camara eje Y
	//if ((interfaz.mouseY - interfaz.oldMouseY) >= 0)
	//{
	//	interfaz.camara.RotateUp(2.0);
	//}
	//else if ((interfaz.mouseY - interfaz.oldMouseY) < 0)
	//{
	//	interfaz.camara.RotateDown(2.0);
	//}

	glutPostRedisplay();
}


void igvInterfaz::inicializa_callbacks() {
	glutKeyboardFunc(set_glutKeyboardFunc);
	glutReshapeFunc(set_glutReshapeFunc);
	glutDisplayFunc(set_glutDisplayFunc);
	glutSpecialFunc(set_glutSpecialFunc);

	glutMouseFunc(set_glutMouseFunc);
	glutPassiveMotionFunc(set_glutMotionFunc);
}
