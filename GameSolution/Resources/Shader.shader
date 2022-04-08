#defaultVertexShader
#version 330 core
layout(location = 0) in vec4 aPos;
layout(location = 1) in vec2 aTextCoords;

out vec2 textCoords;

//uniform mat4 scale;
//uniform vec2 move;
//uniform mat4 rotation;
uniform mat4 transformation;
uniform mat4 view;
uniform vec2 shift;
uniform vec3 move;

void main()
{
	textCoords = vec2(aTextCoords.x + shift.x, aTextCoords.y + shift.y);
	//vec4 varTest = scale * rotation * vec4(aPos.x, aPos.y, 0.0, 1.0);
	gl_Position = transformation * view * vec4(aPos.x + move.x, aPos.y + move.y, 0.0, 1.0);
	//gl_Position = scale * vec4(aPos.x + move.x, aPos.y + move.y, 0.0f, 1.0f);

};
#Ende

#defaultFragmentShader
#version 330 core
out vec4 FragColor;
in vec2 textCoords;
uniform sampler2D ourTexture;

void main()
{
	vec4 texColor = texture(ourTexture, textCoords);
	if (texColor.a < 0.1) {
		discard;
	}

	FragColor = texColor;

}
#Ende

#debugCameraVertexShader
#version 330 core
layout(location = 0) in vec4 aPos;

uniform mat4 transformation;
uniform mat4 view;
uniform vec3 move;

void main()
{

	gl_Position = transformation * view * vec4(aPos.x + move.x, aPos.y, aPos.z, 1.0);

};
#Ende

#debugCameraFragmentShader
#version 330 core
out vec4 FragColor;


void main()
{

	FragColor = vec4(0.5, 1.0, 0.2, 0.5);

}
#Ende