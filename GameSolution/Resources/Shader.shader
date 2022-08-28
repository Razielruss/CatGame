#defaultVertexShader
#version 330 core
layout(location = 0) in vec4 aPos;

void main()
{
	gl_Position = vec4(aPos.x, aPos.y, 0.0, 1.0);
};
#Ende

#defaultFragmentShader
#version 330 core
out vec4 FragColor;

void main()
{

	FragColor = vec4(0.5f, 0.5f, 0.5f, 1.0f);

}
#Ende

#VertexShaderTexture
#version 330 core
layout(location = 0) in vec4 aPos;
layout(location = 1) in vec2 aTextCoords;

out vec2 textCoords;

uniform vec2 shift;

void main()
{
	textCoords = vec2(aTextCoords.x + shift.x, aTextCoords.y + shift.y);
	gl_Position = vec4(aPos.x, aPos.y, 0.0, 1.0);

};
#Ende

#FragmentShaderTexture
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