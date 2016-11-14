#ifdef GL_ES
precision mediump float;

varying lowp vec4 v_fragmentColor;
varying mediump vec2 v_texCoord;
#else
varying vec4 v_fragmentColor;
varying vec2 v_texCoord;
#endif

uniform vec2 u_size;
uniform vec2 u_sizeTile;

void main()
{
        //size(width, height)
        vec2 offsetCoord = vec2(fract(v_texCoord.x / u_sizeTile.x) * u_sizeTile.x, fract(v_texCoord.y / u_sizeTile.y) * u_sizeTile.y);
        gl_FragColor = texture2D(CC_Texture0, offsetCoord);
}
