#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <Windows.h>
#include <chrono>
#include <thread>

#pragma comment(lib,"OpenGL32")

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

int main(void)
{
    float x = 0.5f;
    float x_ = 1.0f;
    float y = 0.5f;
    float y_ = 1.0f;

    float ty = -0.05f;
    float ty_ = -0.55f;

    float tx = -0.05f;
    float tx_ = -0.55f;


    /*float h1 = 0.0f;
    float h2 = -0.04f;*/


    /*float x1 = 0.8f;
    float x2 = 0.83f;

    float x3 = 0.8f;
    float x4 = 0.84f;

    float x5 = 0.8f;
    float x6 = 0.85f;*/

    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);



    while (!glfwWindowShouldClose(window))
    {

        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;




        glClearColor(0, 0, 0, 0);
        glClear(GL_COLOR_BUFFER_BIT);

        // if(key == GLFW_KEY_UP && action == GLFW_PRESS)
                       //p->MoveUp(0.01f)    플레이어 생성 후(헤더파일)
        // if(key == GLFW_KEY_UP && action == GLFW_RELEASE)
                       //p->MoveUp(0.0f)    플레이어 생성 후(헤더파일)



        if (GetAsyncKeyState(VK_DOWN) && 0x8000 || GetAsyncKeyState(VK_DOWN) && 0x8001)
        {
            y -= 0.01f;
            y_ -= 0.01f;
        }
        else
        {
           
        }

        if (GetAsyncKeyState(VK_UP) && 0x8000 || GetAsyncKeyState(VK_UP) && 0x8001)
        {
            y += 0.01f;
            y_ += 0.01f;
        }
        else
        {

        }

        if (GetAsyncKeyState(VK_LEFT) && 0x8000 || GetAsyncKeyState(VK_LEFT) && 0x8001)
        {
            x -= 0.01f;
            x_ -= 0.01f;
        }
        else
        {

        }

        if (GetAsyncKeyState(VK_RIGHT) && 0x8000 || GetAsyncKeyState(VK_RIGHT) && 0x8001)
        {
            x += 0.01f;
            x_ += 0.01f;
        }
        else
        {

        }


        if ((x <= tx && y <= ty && x >= tx_ && y >=ty_) || (x <= tx && y_>=ty_ && x >= tx_ && y_ <= ty)
            || (x_>= tx_ && y_>=ty_ && x_ <= tx && y_ <=ty) || (x_ >= tx_ && y <=ty && x_ <= tx && y >= ty_))   
        {
            std::cout << "충돌중!";
        }
        
        //if (GetAsyncKeyState(VK_SPACE) && 0x8000 || GetAsyncKeyState(VK_SPACE) && 0x8001)        //h1 = 0.0f      h2 = -0.04f
        //{
        //    h1 += 0.007f;
        //    h2 += 0.007f;
        //}
        //else
        //{
        //    h1 -= 0.007f;
        //    h2 -= 0.007f;
        //}

        //if (h1 >= 0.1f && h2 >= 0.06f)
        //{
        //    h1 = 0.1f;
        //    h2 = 0.06f;
        //}

        //if (h1 <= -0.1f && h2 <= -0.1f)
        //{
        //    h1 = -0.1f;
        //    h2 = -0.14f;
        //}



        glPointSize(5);
        glBegin(GL_TRIANGLES);

        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(x, y_);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(x_, y_);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(x_, y);

        glEnd();

        glPointSize(5);
        glBegin(GL_TRIANGLES);

        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(x, y_);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(x, y);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(x_,y);

        glEnd();

        glPointSize(5);
        glBegin(GL_TRIANGLES);

        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(tx, ty_);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(tx, ty);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(tx_, ty);

        glEnd();

        glPointSize(5);
        glBegin(GL_TRIANGLES);

        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(tx, ty_);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(tx_, ty_);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(tx_, ty);

        glEnd();

        //glPointSize(5);
        //glBegin(GL_TRIANGLES);
        ////x좌표 변수화해서 충돌 (if문)
        //glColor3f(1.0f, 0.0f, 0.0f);
        //glVertex2f(-0.8f, h1);
        //glColor3f(1.0f, 0.0f, 0.0f);
        //glVertex2f(-0.83f, h1);
        //glColor3f(1.0f, 0.0f, 0.0f);
        //glVertex2f(-0.83f, h2);
        //glEnd();

        //glPointSize(5);
        //glBegin(GL_TRIANGLES);
        //glColor3f(1.0f, 0.0f, 0.0f);
        //glVertex2f(-0.8f, h1);
        //glColor3f(1.0f, 0.0f, 0.0f);
        //glVertex2f(-0.8f, h2);
        //glColor3f(1.0f, 0.0f, 0.0f);
        //glVertex2f(-0.83f, h2);
        //glEnd();

        //glPointSize(5);
        //glBegin(GL_TRIANGLES);
        ////y좌표 변수화해서 충돌
        //glColor3f(1.0f, 0.0f, 0.0f);
        //glVertex2f(x1, -0.04f);
        //glColor3f(1.0f, 0.0f, 0.0f);
        //glVertex2f(x2, -0.04f);
        //glColor3f(1.0f, 0.0f, 0.0f);
        //glVertex2f(x2, 0.0f);
        //glEnd();

        //glPointSize(5);
        //glBegin(GL_TRIANGLES);
        //glColor3f(1.0f, 0.0f, 0.0f);
        //glVertex2f(x3, -0.18f);
        //glColor3f(1.0f, 0.0f, 0.0f);
        //glVertex2f(x4, -0.18f);
        //glColor3f(1.0f, 0.0f, 0.0f);
        //glVertex2f(x3, -0.1f);
        //glEnd();

        //glPointSize(5);
        //glBegin(GL_TRIANGLES);
        //glColor3f(1.0f, 0.0f, 0.0f);
        //glVertex2f(x5, 0.07f);
        //glColor3f(1.0f, 0.0f, 0.0f);
        //glVertex2f(x6, 0.07f);
        //glColor3f(1.0f, 0.0f, 0.0f);
        //glVertex2f(x6, -0.01f);
        //glEnd();

        //x1 = x1 - 0.007f;
        //x2 = x2 - 0.007f;

        //x3 = x3 - 0.01f;
        //x4 = x4 - 0.01f;

        //x5 = x5 - 0.005f;
        //x6 = x6 - 0.005f;

        //if (x1 <= -1.2f && x2 <= -1.17f)
        //{
        //    x1 = 0.8f;
        //    x2 = 0.83f;
        //}
        //else if (x3 <= -1.2f && x4 <= -1.17f)
        //{
        //    x3 = 0.8f;
        //    x4 = 0.84f;
        //}
        //else if (x5 <= -1.2f && x6 <= -1.17f)
        //{
        //    x5 = 0.8f;
        //    x6 = 0.85f;
        //}

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}