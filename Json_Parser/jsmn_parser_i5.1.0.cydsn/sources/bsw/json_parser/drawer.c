/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

/* [] END OF FILE */
#include "drawer.h"

//creating this enum for tsk_json and tsk_hmi to understand colors
	typedef enum{
		    white         	 , 
		    black         	 , 
		    blue         	 , 
		    bred             , 
		    gred 			 ,
		    gblue			 , 
		    red           	 , 
		    magenta       	 , 
		    green         	 ,
		    cyan          	 , 
		    yellow        	 , 
		    brown 			 , 
		    brred 			 , 
		    gray  			 , 
		    darkblue      	 , 
		    lightblue      	 , 
		    grayblue       	 , 
		    lightgreen     	 , 
		    lgray 			 , 
		    lgrayblue        , 
		    lbblue           , 
		}color_glb_enum; 
/**
 * Translates a JSON tag into a command type for the TFT
 * \param Drawer_t *const me            - [OUT] the next command
 * \param Parser_t *const parser        - [IN/OUT] Parser object pointer
 * \return RC_SUCCESS if a command was found, RC_ERROR_BUFFER_EMTPY if parsing has come to an end, other error code as required
 */
RC_t DRAWER_getNextDrawCommand(Drawer_t *const me, Parser_t *const parser)
{
    char* colors[]={"white", "black", "blue", "bred", "gred",
				  "gblue","red","magenta","green","cyan",
				  "yellow","brown","brred","gray","darkblue",
				  "lightblue","grayblue","lightgreen","lgray","lgrayblue","lbblue",};
    jsmntok_t token;
    token.start=0;
	token.end=0;
	token.size=0;
    char command[]={};
    char color_token[]={};
    strcpy(command,""); 
    strcpy(color_token,"");
    char cordinate_token[]={};
    PARSER_getNextToken(parser, &token);
    PARSER_addEndl(parser);
    if(token.type== JSMN_STRING)
    {
       strcat(command, &parser->content[token.start]); 
    
       if(strcmp(command, "c")==0)// color command
        {
            PARSER_getNextToken(parser, &token);
            PARSER_addEndl(parser);
            if(token.type== JSMN_STRING)
            {
                strcat(color_token, &parser->content[token.start]);
                for(int i=0; i<21;i++)
	            {
		            if(strcmp(colors[i], color_token)==0)//correct color
		            {
                        me->command= DRAWER_CMD_COLOR;
                        me->data.color=i; 
                        return RC_SUCCESS;
                    }
        
                }
                //UART_1_PutString("color not supported by this function\r");
                return RC_ERROR_BAD_PARAM; //color not supported by this function
            }
    
            else
            {
                return RC_ERROR_BAD_PARAM;  
                //error handling "color format not string" 
                //UART_1_PutString("color format not string\r");
            }
        }
        else if(strcmp(command, "d")==0)
        {
            PARSER_getNextToken(parser, &token); 
            if(token.type== JSMN_ARRAY)
            {
                me->command= DRAWER_CMD_DRAW;
                for(int i=0;i<4;i++)
                {
                    PARSER_getNextToken(parser, &token); 
                    PARSER_addEndl(parser);
                    strcat(cordinate_token, &parser->content[token.start]); 
                    me->data.coordinate[i]=atoi(cordinate_token);
                    strcpy(cordinate_token,"");   
                }
                return RC_SUCCESS;
                
            }
            else
            {
                //error handling "drawing coordinates not array type"  
                //UART_1_PutString("drawing coordinates not array type\r"); 
                return RC_ERROR_BAD_PARAM;  
            }
        }
        else
        return RC_ERROR_BAD_PARAM; 
        
    }
    
    else
    {
        // error handling "command format not string"
        //UART_1_PutString("command format not string\r");
        return RC_ERROR_BAD_PARAM;    
    }
  //return RC_SUCCESS;    
}

//--------------------- Debugging aid ---------------------//
/**
 * Prints a drawer object
 * \param Drawer_t *const me            - [IN] the next command
 * \return RC_SUCCESS when printed
 */
RC_t print_Drawer_object(Drawer_t *const me)
{
    char buffer[255];
    if(me->command==DRAWER_CMD_COLOR)
    {
        UART_1_PutString("Command is Color\r");
        itoa(me->data.color,buffer, 10);
        UART_1_PutString("color is ");
        UART_1_PutString(buffer);
        UART_1_PutString("\r");
    }
    else if(me->command==DRAWER_CMD_DRAW)
    {
        UART_1_PutString("Command is Draw\r");
        itoa(me->data.coordinate[0],buffer, 10);
        UART_1_PutString("cordinates are ");
        UART_1_PutString(buffer);
        UART_1_PutString("\r");
        itoa(me->data.coordinate[1],buffer, 10);
        UART_1_PutString(buffer);
        UART_1_PutString("\r");
        itoa(me->data.coordinate[2],buffer, 10);
        UART_1_PutString(buffer);
        UART_1_PutString("\r");
        itoa(me->data.coordinate[3],buffer, 10);
        UART_1_PutString(buffer);
        UART_1_PutString("\r");
    }
    return RC_SUCCESS;
}