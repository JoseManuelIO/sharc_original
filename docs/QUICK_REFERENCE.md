# Quick Reference: What Can I Do With SHARC?

## English / Inglés

### What is SHARC?
SHARC (Simulator for Hardware Architecture and Real-time Control) is a tool that helps you:
- **Simulate control systems** with realistic computational delays
- **Evaluate hardware performance** impact on control algorithms
- **Co-design** control algorithms and the hardware they run on

### What Can You Do?

#### 1. 🚗 Run Example Simulations
Try the included examples to see SHARC in action:

**Adaptive Cruise Control (ACC) - Quick Test:**
```bash
cd examples/acc_example
sharc --config_filename fake_delays.json
```

**Cart Pole Control:**
```bash
cd examples/cartpole
sharc --config_filename default.json
```

#### 2. 🔬 Experiment with Hardware Configurations
Modify chip parameters to see how different hardware affects your control system:
- Processor speed (chip_cycle_time)
- Cache sizes (l1_size, icache_size, dcache_size)
- Memory configurations

Edit configuration files in `simulation_configs/` to test different scenarios.

#### 3. 📊 Analyze Performance
After running simulations, you can:
- View results in `experiments/` folder
- Generate plots using `make_plots.ipynb` (Jupyter notebooks)
- Analyze computation times and control performance
- Compare serial vs parallel execution modes

#### 4. 🛠️ Create Your Own Projects
Build custom control simulations:
1. Create a new project folder in `examples/`
2. Define your system dynamics (Python)
3. Implement your controller (C++)
4. Configure simulation parameters (JSON)
5. Run and analyze!

See: [Tutorial: Implementing Custom Dynamics and Controllers](Tutorial:%20Implementing%20Custom%20Dynamics%20and%20Controllers.md)

#### 5. 🧪 Test Different Modes
- **Serial Mode**: Simulates each time step sequentially
- **Parallel Mode**: Simulates multiple time steps in parallel
- **Fake Delays**: Quick testing without full hardware simulation

### Quick Start Workflows

#### Workflow 1: First-Time User
```bash
# 1. Clone and setup
git clone git@github.com:pwintz/sharc.git && cd sharc
./setup_sharc.sh

# 2. Run quick example
cd examples/acc_example
sharc --config_filename fake_delays.json

# 3. View results
jupyter notebook make_plots.ipynb
```

#### Workflow 2: Researcher/Developer
```bash
# 1. Create your project
mkdir examples/my_project
cp -r examples/acc_example/* examples/my_project/

# 2. Modify dynamics and controller
# Edit dynamics/dynamics.py
# Edit controllers/src/my_controller.cpp

# 3. Configure and run
cd examples/my_project
# Edit simulation_configs/default.json
sharc --config_filename default.json

# 4. Analyze results
# Check experiments/ folder
```

#### Workflow 3: Hardware Designer
```bash
# Test different chip configurations
cd examples/acc_example

# Edit simulation_configs/custom.json to change:
# - chip_cycle_time (processor speed)
# - cache sizes
# - memory parameters

sharc --config_filename custom.json

# Compare results with baseline
python generate_example_figures.py
```

### Common Use Cases

1. **Control Algorithm Research**: Test how computational delays affect control performance
2. **Hardware-Software Co-design**: Find optimal hardware configurations for control systems
3. **Real-time Systems Analysis**: Understand timing constraints in cyber-physical systems
4. **Education**: Learn about the interaction between computation and control

### Key Files and Directories

- `examples/` - Pre-built example projects
- `README.md` - Comprehensive documentation
- `setup_sharc.sh` - Automated setup script
- `Dockerfile` - Container configuration
- `docs/` - Additional documentation
- `resources/sharc/` - Core SHARC Python package

### Need Help?
- Read the [full README](../README.md) for detailed instructions
- Check the [Tutorial](Tutorial:%20Implementing%20Custom%20Dynamics%20and%20Controllers.md) for custom implementations
- Review example projects in `examples/`

---

## Español / Spanish

### ¿Qué es SHARC?
SHARC (Simulador para Arquitectura de Hardware y Control en Tiempo Real) es una herramienta que te ayuda a:
- **Simular sistemas de control** con retardos computacionales realistas
- **Evaluar el impacto del rendimiento del hardware** en algoritmos de control
- **Co-diseñar** algoritmos de control y el hardware en el que se ejecutan

### ¿Qué Puedes Hacer?

#### 1. 🚗 Ejecutar Simulaciones de Ejemplo
Prueba los ejemplos incluidos para ver SHARC en acción:

**Control de Crucero Adaptativo (ACC) - Prueba Rápida:**
```bash
cd examples/acc_example
sharc --config_filename fake_delays.json
```

**Control de Péndulo Invertido sobre Carro:**
```bash
cd examples/cartpole
sharc --config_filename default.json
```

#### 2. 🔬 Experimentar con Configuraciones de Hardware
Modifica parámetros del chip para ver cómo diferentes hardwares afectan tu sistema de control:
- Velocidad del procesador (chip_cycle_time)
- Tamaños de caché (l1_size, icache_size, dcache_size)
- Configuraciones de memoria

Edita archivos de configuración en `simulation_configs/` para probar diferentes escenarios.

#### 3. 📊 Analizar Rendimiento
Después de ejecutar simulaciones, puedes:
- Ver resultados en la carpeta `experiments/`
- Generar gráficos usando `make_plots.ipynb` (Jupyter notebooks)
- Analizar tiempos de cómputo y rendimiento del control
- Comparar modos de ejecución serial vs paralelo

#### 4. 🛠️ Crear Tus Propios Proyectos
Construye simulaciones de control personalizadas:
1. Crea una nueva carpeta de proyecto en `examples/`
2. Define la dinámica de tu sistema (Python)
3. Implementa tu controlador (C++)
4. Configura parámetros de simulación (JSON)
5. ¡Ejecuta y analiza!

Ver: [Tutorial: Implementando Dinámicas y Controladores Personalizados](Tutorial:%20Implementing%20Custom%20Dynamics%20and%20Controllers.md)

#### 5. 🧪 Probar Diferentes Modos
- **Modo Serial**: Simula cada paso de tiempo secuencialmente
- **Modo Paralelo**: Simula múltiples pasos de tiempo en paralelo
- **Retardos Falsos**: Pruebas rápidas sin simulación completa de hardware

### Flujos de Trabajo Rápidos

#### Flujo 1: Usuario Principiante
```bash
# 1. Clonar y configurar
git clone git@github.com:pwintz/sharc.git && cd sharc
./setup_sharc.sh

# 2. Ejecutar ejemplo rápido
cd examples/acc_example
sharc --config_filename fake_delays.json

# 3. Ver resultados
jupyter notebook make_plots.ipynb
```

#### Flujo 2: Investigador/Desarrollador
```bash
# 1. Crear tu proyecto
mkdir examples/mi_proyecto
cp -r examples/acc_example/* examples/mi_proyecto/

# 2. Modificar dinámica y controlador
# Editar dynamics/dynamics.py
# Editar controllers/src/mi_controlador.cpp

# 3. Configurar y ejecutar
cd examples/mi_proyecto
# Editar simulation_configs/default.json
sharc --config_filename default.json

# 4. Analizar resultados
# Revisar carpeta experiments/
```

#### Flujo 3: Diseñador de Hardware
```bash
# Probar diferentes configuraciones de chip
cd examples/acc_example

# Editar simulation_configs/custom.json para cambiar:
# - chip_cycle_time (velocidad del procesador)
# - tamaños de caché
# - parámetros de memoria

sharc --config_filename custom.json

# Comparar resultados con línea base
python generate_example_figures.py
```

### Casos de Uso Comunes

1. **Investigación en Algoritmos de Control**: Probar cómo los retardos computacionales afectan el rendimiento del control
2. **Co-diseño Hardware-Software**: Encontrar configuraciones óptimas de hardware para sistemas de control
3. **Análisis de Sistemas en Tiempo Real**: Entender restricciones de tiempo en sistemas ciber-físicos
4. **Educación**: Aprender sobre la interacción entre computación y control

### Archivos y Directorios Clave

- `examples/` - Proyectos de ejemplo preconstruidos
- `README.md` - Documentación completa
- `setup_sharc.sh` - Script de configuración automática
- `Dockerfile` - Configuración de contenedor
- `docs/` - Documentación adicional
- `resources/sharc/` - Paquete Python central de SHARC

### ¿Necesitas Ayuda?
- Lee el [README completo](../README.md) para instrucciones detalladas
- Revisa el [Tutorial](Tutorial:%20Implementing%20Custom%20Dynamics%20and%20Controllers.md) para implementaciones personalizadas
- Examina proyectos de ejemplo en `examples/`

---

## Key Commands Cheat Sheet / Hoja de Referencia de Comandos Clave

```bash
# Setup / Configuración
./setup_sharc.sh                           # Initial setup / Configuración inicial

# Run examples / Ejecutar ejemplos
sharc --config_filename <config.json>      # Run simulation / Ejecutar simulación
sharc --failfast                           # Stop on first error / Detener en primer error

# Docker commands / Comandos Docker
docker pull pwintz/sharc:latest            # Pull image / Descargar imagen
docker run -it sharc:latest                # Interactive container / Contenedor interactivo
docker build --tag sharc:my_tag .          # Build image / Construir imagen

# Development / Desarrollo
jupyter notebook make_plots.ipynb          # Visualize results / Visualizar resultados
python generate_example_figures.py         # Generate plots / Generar gráficos
```
