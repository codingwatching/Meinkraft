cmake_minimum_required(VERSION 3.28)

add_compile_options($<$<COMPILE_LANGUAGE:C>:/Zc:__STDC__>)
add_compile_options($<$<COMPILE_LANGUAGE:C>:/Zc:__cplusplus>)
add_compile_options($<$<COMPILE_LANGUAGE:C>:/utf-8>)

add_compile_options($<$<COMPILE_LANGUAGE:CXX>:/Zc:__STDC__>)
add_compile_options($<$<COMPILE_LANGUAGE:CXX>:/Zc:__cplusplus>)
add_compile_options($<$<COMPILE_LANGUAGE:CXX>:/utf-8>)

# ---- vcpkg ----

cmake_path(CONVERT "$ENV{VCPKG_ROOT}" TO_CMAKE_PATH_LIST VCPKG_ROOT)

set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
set(VCPKG_TARGET_TRIPLET "x64-windows-static-md")

# ---- Project ----

project(Meinkraft)

# ---- Executable ----

add_executable(Meinkraft)

target_sources(Meinkraft PRIVATE
	"src/Meinkraft/Main.cpp"
	"src/Meinkraft/Rendering/Renderer.cpp"
	"src/Meinkraft/World.cpp"
	"src/Meinkraft/Toolbox.cpp"
	"src/Meinkraft/Camera.cpp"
	"src/Meinkraft/Chunk.cpp"
	"src/Meinkraft/WorldGenerator.cpp"
	"src/Meinkraft/MountainGenerator.cpp"
	"src/Meinkraft/NoiseGenerator.cpp"
	"src/Meinkraft/GL/ShaderProgram.cpp"
	"src/Meinkraft/GL/ShaderProgram_setUniform.cpp"
	"src/Meinkraft/Texture/Block/BlockTexture.cpp"
	"src/Meinkraft/BlockContainer.cpp"
	"src/Meinkraft/ChunkBuffer.cpp"
	"src/Meinkraft/ChunkBufferSegment.cpp"
	"src/Meinkraft/ChunkBufferManager.cpp"
	"src/Meinkraft/Texture/Block/BlockTextureManager.cpp"
	"src/Meinkraft/ConcurrentChunkTaskQueue.cpp"
	"src/Meinkraft/MainThreadChunkTaskQueue.cpp"
	"src/Meinkraft/Helper/SpecHelper.cpp"
	"src/Meinkraft/LibImpl.cpp"
	"src/Meinkraft/Rendering/RenderPass/ChunksPass.cpp"
	"src/Meinkraft/Rendering/RenderPass/SkyboxPass.cpp"
	"src/Meinkraft/Block/BlockManager.cpp"
	"src/Meinkraft/Block/VertexGenerators.cpp"
)

target_sources(Meinkraft PRIVATE FILE_SET HEADERS BASE_DIRS "src" FILES
	"src/Meinkraft/Rendering/Renderer.h"
	"src/Meinkraft/World.h"
	"src/Meinkraft/Toolbox.h"
	"src/Meinkraft/Camera.h"
	"src/Meinkraft/Chunk.h"
	"src/Meinkraft/BlockId.h"
	"src/Meinkraft/WorldGenerator.h"
	"src/Meinkraft/MountainGenerator.h"
	"src/Meinkraft/NoiseGenerator.h"
	"src/Meinkraft/Helper/MathHelper.h"
	"src/Meinkraft/GL/ShaderProgram.h"
	"src/Meinkraft/Helper/FileHelper.h"
	"src/Meinkraft/Helper/ShaderHelper.h"
	"src/Meinkraft/Helper/StringHelper.h"
	"src/Meinkraft/Texture/Block/BlockTexture.h"
	"src/Meinkraft/BlockContainer.h"
	"src/Meinkraft/ChunkBuffer.h"
	"src/Meinkraft/ChunkBufferSegment.h"
	"src/Meinkraft/GL/VertexData.h"
	"src/Meinkraft/ChunkBufferManager.h"
	"src/Meinkraft/Block/BlockDefinition.h"
	"src/Meinkraft/Block/BlockType.h"
	"src/Meinkraft/Texture/Block/BlockTextureManager.h"
	"src/Meinkraft/Texture/Block/BlockTextureId.h"
	"src/Meinkraft/GL/ShaderProgramCreateInfo.h"
	"src/Meinkraft/ConcurrentChunkTaskQueue.h"
	"src/Meinkraft/MainThreadChunkTaskQueue.h"
	"src/Meinkraft/Helper/SpecHelper.h"
	"src/Meinkraft/Rendering/RenderPass/RenderPass.h"
	"src/Meinkraft/Rendering/RenderPass/ChunksPass.h"
	"src/Meinkraft/Rendering/RenderPass/SkyboxPass.h"
	"src/Meinkraft/Block/VertexGenerators.h"
	"src/Meinkraft/Block/BlockManager.h"
)

set_target_properties(Meinkraft PROPERTIES CXX_STANDARD 20)
set_target_properties(Meinkraft PROPERTIES CXX_STANDARD_REQUIRED ON)
set_target_properties(Meinkraft PROPERTIES CXX_EXTENSIONS OFF)
set_target_properties(Meinkraft PROPERTIES INTERPROCEDURAL_OPTIMIZATION_RELWITHDEBINFO TRUE)
set_target_properties(Meinkraft PROPERTIES INTERPROCEDURAL_OPTIMIZATION_RELEASE TRUE)
set_target_properties(Meinkraft PROPERTIES DEBUG_POSTFIX d)
#set_target_properties(Meinkraft PROPERTIES WIN32_EXECUTABLE ON)

add_custom_target(copy_resources
		COMMAND robocopy ${PROJECT_SOURCE_DIR}/resources/ ${PROJECT_BINARY_DIR}/resources /E /NS /NC /NFL /NDL /NP /NJH /NJS || cmd /c "exit /b 0")
add_dependencies(Meinkraft copy_resources)

# ---- Dependency: glfw/glfw ----

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(Meinkraft PRIVATE glfw)

# ---- Dependency: g-truc/glm ----

find_package(glm CONFIG REQUIRED)
target_link_libraries(Meinkraft PRIVATE glm::glm)

target_compile_definitions(Meinkraft PRIVATE GLM_ENABLE_EXPERIMENTAL)

# ---- Dependency: nothings/stb ----

find_package(Stb REQUIRED)
target_include_directories(Meinkraft PRIVATE ${Stb_INCLUDE_DIR})

# ---- Dependency: Neargye/magic_enum ----

find_package(magic_enum CONFIG REQUIRED)
target_link_libraries(Meinkraft PRIVATE magic_enum::magic_enum)

# ---- Dependency: Dav1dde/glad ----

add_subdirectory("vendor/glad")
target_link_libraries(Meinkraft PRIVATE glad)

# ---- Dependency: Auburn/FastNoiseLite ----

add_subdirectory("vendor/FastNoiseLite")
target_link_libraries(Meinkraft PRIVATE FastNoiseLite)