#include <iostream>
#include <functional>
#include <memory>

int main() {
    return EXIT_SUCCESS;
}

class Wire { 
    virtual bool isConnected() = 0;
    virtual void connect() = 0;
    virtual void disconnect() = 0;
    virtual size_t write() = 0;
    virtual void subscribe_to_event(std::string event, std::function<void(char *)>) = 0;
};

class Battery {
    Battery(uint8_t sensor_pin) {
        this->sensor_pin = sensor_pin;
    }
private:
    uint8_t sensor_pin;
    uint8_t percentage;
};

class Bobot {
public:
    Bobot(Engine &engine, Wire &wire) {
        this->engine = std::shared_ptr<Engine>(&engine);
        this->wire = std::unique_ptr<Wire>(&wire);
    }
    void turn_on();
    void turn_off();
    void connect();
    void disconnect();
    std::shared_ptr<Engine> get_engine() {
        return this->engine;
    }
private:
    std::shared_ptr<Engine> engine;
    std::unique_ptr<Wire> wire;
};

class Engine {
public:
    struct engine_configuration_t {
        uint8_t motor1_pin1;
        uint8_t motor1_pin2;
        uint8_t motor2_pin1;
        uint8_t motor2_pin2;
        uint8_t motor1_pwm_pin;
        uint8_t motor2_pwm_pin;
    };
    enum direction_t { forward = 0, backward };
    struct control_package {
        uint16_t left_power;
        uint16_t right_power;
        direction_t direction;
    };
    Engine(Battery &battery, engine_configuration_t config) {
        this->battery = std::unique_ptr<Battery>(&battery);
        this->config = config;
    }
    void speed();
    void turn();
private:
    std::unique_ptr<Battery> battery;
    engine_configuration_t config;
};