#ifdef GL_ES
precision mediump float;
#endif

varying vec4 v_fragmentColor;
varying vec2 v_texCoord;

uniform vec2 u_resolution;    //解析度？
uniform float u_intensity;    //强度

vec3 noise(vec2 uv)
{
    vec2 p = abs(sin(uv * 13.0 + uv.x * CC_Time[1] * sin(uv.y)));
    
    return vec3(sin(0.2 * CC_Time[1] + sin(p * 0.5) * CC_Time[1] / cos(50.0)) * 10.0, 0.3 + 0.5 * abs(sin(CC_Time[1] * tan(5.0))));
}

void main()
{
    gl_FragColor.xyz = u_intensity * noise(gl_FragCoord.xy / sin(u_resolution.xy * CC_Time[1] * 0.01)) + (1.0 - u_intensity) * texture2D(CC_Texture0, v_texCoord.xy).xyz;
    gl_FragColor.w = 1.0;
}
