
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void update(GLFWwindow* window);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

int main() {

    //potrebno je da inicijalizujemo
    glfwInit();
    //OpenGL 3.3 Core
    //ovim govorimo koju verziju OpenGL-a koristimo
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //sada kreiramo prozor

    GLFWwindow *window=glfwCreateWindow(800, 600, "hello_window", nullptr, nullptr);
    //poslednja dva argumenta ignorisemo
    //ova funkcija vraca pokazivac na prozor koji je kreirala

    //provera da li smo dobro napravili prozor
    //ukoliko je taj pokazivac null kreiranje prozora nije uspelo
    //i treba da terminisemo izvrsavanje aplikacije
    if(window== nullptr) {
        std::cout << "Failed create a window\n";
        glfwTerminate();
        return EXIT_FAILURE;
    }

    //treba da kazemo OpenGL-u da je to prozor u kome cemo crtati
    glfwMakeContextCurrent(window);

    //ova funkcija koju smo definisali se poziva svaki put kada se promeni velicina prozora
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    glfwSetKeyCallback(window, key_callback);

    //sada ucitavamo sve OpenGL funkcije koristeci glad biblioteku

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Failed to init GLAD\n";
        glfwTerminate();
        return EXIT_FAILURE;
    }

    //petlja renderovanja
    while(!glfwWindowShouldClose(window)){
        glfwPollEvents();
        update(window);
        glfwSwapBuffers(window);
    }

    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}

//nama su za sada bitni parametri prozor, kljuc i akcija
//ova funkcija nam omogucava da ako stisnemo jednom g on ce ga ispisati samo jednom
//a ako ovo stavimo u update onda je moguce da ispise i po vise puta
//jer u svakoj iteraciji petlje pollEvents vrsi resetovanje svih stanja za sve dugmice
//na podrazumevana
//mi ne mozemo toliko kratko da drzimo dugme da se ono ispise samo jednom jer recimo
//moze da se prodje kroz petlju 60 puta u sekundi
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){

    if(key==GLFW_KEY_G && action==GLFW_PRESS){
        std :: cerr << "G\n";
    }

    if(key==GLFW_KEY_ESCAPE && action==GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}


void update(GLFWwindow* window){

}
