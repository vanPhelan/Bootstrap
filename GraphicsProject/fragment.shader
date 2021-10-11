#version 410

in vec4 fPosition;
in vec4 fNormal;
in vec4 fColor;

out vec4 pColor;

void main() {
	pColor = fColor;
}