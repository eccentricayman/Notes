# SoftDev::C is for Cookie, but Sessions are Secure

Do Now: Demo

  


Cookies and Sessions

  


     Cookies are files that websites will save to your web browser to store information on a local machine.

  


     Useful for keeping track of persistent information like login credentials.

  


    Session

  


          Flask sessions are securely signed cookies.

          

          Since they are encrypted, they cannot be modified by the user of the local machine.

  


          The session object works exactly like a dictionary

  


               Add data to a session:

                    session[KEY] = DATA

                    

               Remove data from a session:

                    session.pop(KEY)

  


          In order for the session to be encrypted, we need to set a private key in our app:

  


               APP.secret_key = &lt;RANDOM STRING&gt;

               

                    good way to get random data: os.urandom(32)

  


                         Returns 32 random bits of data as a string

  


                    NEVER EVER EVER publish the secret key in a public place (like github)

  


Continued:

[SoftDev::URL binding is the art of redirection](evernote:///view/2147483647/s466/453d5806-8abe-434a-a15e-9faefefafcd1/453d5806-8abe-434a-a15e-9faefefafcd1/)
