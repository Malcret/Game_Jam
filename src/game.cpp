#include "game.hpp"

Game::Game(GLFWwindow *window, unsigned int screen_width, unsigned int screen_height)
    : m_window(window), m_screen_width(screen_width), m_screen_height(screen_height) {

    m_game_state = Game_State::MAIN_MENU;
    m_shader = new Shader("shaders/sprite.vert", "shaders/sprite.frag");
    init_main_menu();
}

Game::~Game() {

}

void Game::init_main_menu() {
    m_texture = new Texture("textures/Box.png", true);

    float vertices[] = {
        // positions          // texture coords
         0.5f,  0.5f, 0.0f,   1.0f, 1.0f, // top right
         0.5f, -0.5f, 0.0f,   1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, // bottom left
        -0.5f,  0.5f, 0.0f,   0.0f, 1.0f  // top left 
    };
    unsigned int indices[] = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };
    unsigned int m_VBO, m_VAO, m_EBO;
    glGenVertexArrays(1, &m_VAO);
    glGenBuffers(1, &m_VBO);
    glGenBuffers(1, &m_EBO);

    glBindVertexArray(m_VAO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    m_shader->use();
    m_shader->setInt("texture1", m_texture->getID());
}

void Game::loop() {

    m_texture->use();
    m_shader->use();

    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::ortho(static_cast<float>(-m_screen_width), static_cast<float>(m_screen_width), static_cast<float>(m_screen_height), static_cast<float>(-m_screen_height), 0.0f, 0.0f);

    m_shader->setMat4("model", model);
    m_shader->setMat4("projection", projection);
    m_shader->setMat4("view", view);

    model = glm::mat4();
    model = glm::translate(model, glm::vec3(1.0f, 1.0f, 0.0f));
    model = glm::scale(model, glm::vec3(1.0f, 1.0f, 0.0f));

    m_shader->setMat4("model", model);

    glBindVertexArray(m_VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
