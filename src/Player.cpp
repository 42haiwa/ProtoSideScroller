#include "Player.h"

Player::Player(std::string const & path) {
    m_texture = sf::Texture{};
    m_pos = sf::Vector2f{100, 0};
    m_sprite = sf::Sprite{};
    m_box = sf::RectangleShape{sf::Vector2f{TEXTURE_POS_X, 96}};
    m_moveSpeed = sf::Vector2f{400.f, 0.f};
    m_scale = sf::Vector2f{2.f, 2.f};
    m_view = sf::View{};
    m_grounded = false;
    m_spaceKeyReleased = false;
    m_jumpCount = 0;

    m_texture.loadFromFile(path, sf::IntRect{0, 0, TEXTURE_POS_X, 96});
    m_texture.setSmooth(false);
    m_sprite.setTexture(m_texture);
    m_box.setFillColor(sf::Color::Transparent);
    m_box.setOutlineThickness(1.f);
    m_box.setOutlineColor(sf::Color::White);
    m_sprite.setScale(m_scale);
    m_sprite.setOrigin(sf::Vector2f{m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().height / 2});
    m_box.setOrigin(m_sprite.getOrigin());
}

void Player::update(sf::RenderWindow & window) {
    // m_view.reset(sf::FloatRect{m_pos.x - (W_WIDTH / 2), 0, W_WIDTH, W_HEIGHT});
    // window.setView(m_view);

    sf::Time dt = m_clock.restart();
    sf::Time animDt = m_animClock.getElapsedTime();

    if (animDt.asSeconds() > ANIMATION_SPEED) m_animClock.restart();

    checkKeyboard(dt, animDt);
    applyGravity(dt);
}

void Player::render(sf::RenderWindow & window) const {
    window.draw(m_sprite);
    window.draw(m_box);
}

void Player::checkKeyboard(sf::Time dt, sf::Time animDt) {
    std::cout << animDt.asSeconds() << std::endl;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        m_pos.x += m_moveSpeed.x * dt.asSeconds();

        m_scale.x = 2.f;
        m_sprite.setScale(m_scale);

        if (animDt.asSeconds() <= ANIMATION_SPEED / 8.f) m_texture.loadFromFile("assets/player/Player.png", sf::IntRect{0, 0, TEXTURE_POS_X, 96});
        if (animDt.asSeconds() > ANIMATION_SPEED / 8.f && animDt.asSeconds() <= 2 * (ANIMATION_SPEED / 8.f)) m_texture.loadFromFile("assets/player/Player.png", sf::IntRect{TEXTURE_POS_X, 0, TEXTURE_POS_X, 96});
        if (animDt.asSeconds() > 2 * (ANIMATION_SPEED / 8.f) && animDt.asSeconds() <= 3 * (ANIMATION_SPEED / 8.f)) m_texture.loadFromFile("assets/player/Player.png", sf::IntRect{2 * TEXTURE_POS_X, 0, TEXTURE_POS_X, 96});
        if (animDt.asSeconds() > 3 * (ANIMATION_SPEED / 8.f) && animDt.asSeconds() <= 4 * (ANIMATION_SPEED / 8.f)) m_texture.loadFromFile("assets/player/Player.png", sf::IntRect{3 * TEXTURE_POS_X, 0, TEXTURE_POS_X, 96});
        if (animDt.asSeconds() > 4 * (ANIMATION_SPEED / 8.f) && animDt.asSeconds() <= 5 * (ANIMATION_SPEED / 8.f)) m_texture.loadFromFile("assets/player/Player.png", sf::IntRect{4 * TEXTURE_POS_X, 0, TEXTURE_POS_X, 96});
        if (animDt.asSeconds() > 5 * (ANIMATION_SPEED / 8.f) && animDt.asSeconds() <= 6 * (ANIMATION_SPEED / 8.f)) m_texture.loadFromFile("assets/player/Player.png", sf::IntRect{5 * TEXTURE_POS_X, 0, TEXTURE_POS_X, 96});
        if (animDt.asSeconds() > 6 * (ANIMATION_SPEED / 8.f) && animDt.asSeconds() <= 7 * (ANIMATION_SPEED / 8.f)) m_texture.loadFromFile("assets/player/Player.png", sf::IntRect{6 * TEXTURE_POS_X, 0, TEXTURE_POS_X, 96});
        if (animDt.asSeconds() > 7 * (ANIMATION_SPEED / 8.f) && animDt.asSeconds() <= 8 * (ANIMATION_SPEED / 8.f)) m_texture.loadFromFile("assets/player/Player.png", sf::IntRect{7 * TEXTURE_POS_X, 0, TEXTURE_POS_X, 96});
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        m_pos.x -= m_moveSpeed.x * dt.asSeconds();

        m_scale.x = -2.f;
        m_sprite.setScale(m_scale);

        if (animDt.asSeconds() <= ANIMATION_SPEED / 8.f) m_texture.loadFromFile("assets/player/Player.png", sf::IntRect{0, 0, TEXTURE_POS_X, 96});
        if (animDt.asSeconds() > ANIMATION_SPEED / 8.f && animDt.asSeconds() <= 2 * (ANIMATION_SPEED / 8.f)) m_texture.loadFromFile("assets/player/Player.png", sf::IntRect{TEXTURE_POS_X, 0, TEXTURE_POS_X, 96});
        if (animDt.asSeconds() > 2 * (ANIMATION_SPEED / 8.f) && animDt.asSeconds() <= 3 * (ANIMATION_SPEED / 8.f)) m_texture.loadFromFile("assets/player/Player.png", sf::IntRect{2 * TEXTURE_POS_X, 0, TEXTURE_POS_X, 96});
        if (animDt.asSeconds() > 3 * (ANIMATION_SPEED / 8.f) && animDt.asSeconds() <= 4 * (ANIMATION_SPEED / 8.f)) m_texture.loadFromFile("assets/player/Player.png", sf::IntRect{3 * TEXTURE_POS_X, 0, TEXTURE_POS_X, 96});
        if (animDt.asSeconds() > 4 * (ANIMATION_SPEED / 8.f) && animDt.asSeconds() <= 5 * (ANIMATION_SPEED / 8.f)) m_texture.loadFromFile("assets/player/Player.png", sf::IntRect{4 * TEXTURE_POS_X, 0, TEXTURE_POS_X, 96});
        if (animDt.asSeconds() > 5 * (ANIMATION_SPEED / 8.f) && animDt.asSeconds() <= 6 * (ANIMATION_SPEED / 8.f)) m_texture.loadFromFile("assets/player/Player.png", sf::IntRect{5 * TEXTURE_POS_X, 0, TEXTURE_POS_X, 96});
        if (animDt.asSeconds() > 6 * (ANIMATION_SPEED / 8.f) && animDt.asSeconds() <= 7 * (ANIMATION_SPEED / 8.f)) m_texture.loadFromFile("assets/player/Player.png", sf::IntRect{6 * TEXTURE_POS_X, 0, TEXTURE_POS_X, 96});
        if (animDt.asSeconds() > 7 * (ANIMATION_SPEED / 8.f) && animDt.asSeconds() <= 8 * (ANIMATION_SPEED / 8.f)) m_texture.loadFromFile("assets/player/Player.png", sf::IntRect{7 * TEXTURE_POS_X, 0, TEXTURE_POS_X, 96});
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        if (m_grounded && m_spaceKeyReleased) {
            m_grounded = false;
            m_moveSpeed.y = JUMP_SPEED * 1.2f;
            m_jumpCount += 1;
            m_spaceKeyReleased = false;
        } else if (m_jumpCount == 1 && m_spaceKeyReleased) {
            m_moveSpeed.y = JUMP_SPEED;
            m_jumpCount += 1;
            m_spaceKeyReleased = false;
        }
    }

    if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))) {
        m_texture.loadFromFile("assets/player/Player.png", sf::IntRect{0, 0, TEXTURE_POS_X, 96});
    }

    if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))) {
        m_spaceKeyReleased = true;
    }

    m_sprite.setPosition(m_pos);
    m_box.setPosition(m_pos);
}

void Player::applyGravity(sf::Time dt) {
    if (!m_grounded) {
        m_moveSpeed.y += GRAVITY * dt.asSeconds();
        m_pos.y += m_moveSpeed.y * dt.asSeconds();

        m_sprite.setPosition(m_pos);
        m_box.setPosition(m_pos);
    }

    if (m_pos.y > MIN_PLATFORME_Y) {
        m_pos.y = MIN_PLATFORME_Y;
        m_grounded = true;
        m_jumpCount = 0;
    }
}
