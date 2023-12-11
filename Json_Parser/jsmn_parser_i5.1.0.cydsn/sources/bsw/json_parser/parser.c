#include "parser.h"
/**
 * Create a parser object
 * \param Parser_t *const me - [OUT] Parser bject pointer
 * \return RC_SUCCESS
 */
RC_t PARSER_init(Parser_t *const me)
{
    jsmn_init(&me->parser);
    me->nextFreePos=0;
    me->nextToken=0;
      for (uint8_t i = 0; i < PARSERMAXTOKEN; i++)
  {
	  me->token[i].start=0;
	  me->token[i].end=0;
	  me->token[i].size=0;
  }
    
    return RC_SUCCESS;
    
}

/**
 * Clear a parser object
 * \param Parser_t *const me - [OUT] Parser object pointer
 * \return RC_SUCCESS
 */
RC_t PARSER_clear(Parser_t *const me)
{
    char buffer[255];
    jsmn_init(&me->parser);//point to the first token position
    me->content[0]= '\0'; //clear the content array after each protocol
    me->nextFreePos=0;//point to the first potiion of the content array
    for (uint8_t i = 0; i < PARSERMAXTOKEN; i++)
    {
	  me->token[i].start=0;
	  me->token[i].end=0;
	  me->token[i].size=0;
    }
    me->nextToken=0;//reset next token
    return RC_SUCCESS;
}
/**
 * Add a char to the buffer
 * \param Parser_t *const me - [IN/OUT] Parser bject pointer
 * \param char data - [IN] next char of the json string
 * \return RC_SUCCESS
 */
RC_t PARSER_addChar(Parser_t *const me, char data)
{
    if(me->nextFreePos>200)
    {
       return RC_ERROR_MEMORY; //if one protocol has characters more than 200 
    }
    
    me->content[me->nextFreePos] = data;
    me->nextFreePos++;
    return RC_SUCCESS;    
}

/**
 * Add an endl to the buffer
 * \param Parser_t *const me - [IN/OUT] Parser bject pointer
 * \return RC_SUCCESS
 */
RC_t PARSER_addEndl(Parser_t *const me)
{
    
    me->content[me->token[me->nextToken].end] = '\0';
    return RC_SUCCESS;
}

/**
 * Perform the parsing and create the token list
 * \param Parser_t *const me - [IN/OUT] Parser bject pointer
 * \param char data - [IN] next char of the json string
 * \return RC_SUCCESS
 */
RC_t PARSER_parse(Parser_t *const me)
{
    uint8_t r;
    r = jsmn_parse(&me->parser, me->content, me->nextFreePos, me->token,sizeof(me->token) / sizeof(me->token[0]));

    return RC_SUCCESS;
}

/**
 * Get the next token of the list
 * \param Parser_t *const me - [IN/OUT] Parser bject pointer
 * \param jsmntok_t const* token - [OUT] Next token of the list
 * \return RC_SUCCESS
 */
RC_t PARSER_getNextToken(Parser_t *const me, jsmntok_t *const token)
{
    me->nextToken++;
    token->start= me->token[me->nextToken].start;
    token->end= me->token[me->nextToken].end;
    token->size= me->token[me->nextToken].size;
    token->type= me->token[me->nextToken].type;  
    

    return RC_SUCCESS;
}

/**
 * Reset token iterator
 * \param Parser_t *const me - [IN/OUT] Parser bject pointer
 * \return RC_SUCCESS
 */
RC_t PARSER_resetNextToken(Parser_t *const me)
{
     me->nextToken=0;
    return RC_SUCCESS;
}
//--------------------- Some debugging aid


/**
 * Prints string content inside a parser object
 * \param Parser_t *const me - [OUT] Parser bject pointer
 * \return RC_SUCCESS
 */
RC_t PARSER_dbg_printContent(Parser_t *const me)
{
    UART_1_PutString("Processing data  ");
    for(uint16_t i=0; i<me->nextFreePos;i++)
    {
      UART_1_PutChar(me->content[i]);  
    }
    UART_1_PutString("  length  ");
    char buffer[255];
    itoa(me->nextFreePos,buffer, 10);
    UART_1_PutString(buffer);
    UART_1_PutString("\r");
    
    return RC_SUCCESS;
    
}

/**
 * Print a parser object content
 * \param Parser_t *const me - [OUT] Parser bject pointer
 * \return RC_SUCCESS
 */
RC_t PARSER_dbg_printToken(Parser_t *const me)
{

    int r=0;
    char buffer[255];
    while(me->token[r].end!=0){r++;}
    for(int j=0 ;j<r;j++)
            {
                UART_1_PutString("Parsed token ");
                itoa(j,buffer, 10);
                UART_1_PutString(buffer);
                UART_1_PutString(" - ");
                switch(me->token[j].type)
                {
                    case 0: UART_1_PutString("JSMN_UNDEFINED");//JSMN_UNDEFINED = 0,  --0 
                    break;
                    
                    case 1:UART_1_PutString("JSMN_OBJECT");//JSMN_OBJECT = 1 << 0, -- 1
                    break;
                    
                    case 2:UART_1_PutString("JSMN_ARRAY");//JSMN_ARRAY = 1 << 1,  -- 2
                    break;
                    
                    case 4:UART_1_PutString("JSMN_STRING");//JSMN_STRING = 1 << 2, -- 4
                    break;
                    
                    case 8:UART_1_PutString("JSMN_PRIMITIVE");//JSMN_PRIMITIVE = 1 << 3 -- 8
                    break;
                    
                    
                }
                UART_1_PutString(" : ");
                for(int i=0 ;i<(me->token[j].end - me->token[j].start);i++)//Each token
                {
                    UART_1_PutChar(me->content[i+ me->token[j].start]);
            
                }
                UART_1_PutString("\r");
            }  
    
    return RC_SUCCESS;
    
}
