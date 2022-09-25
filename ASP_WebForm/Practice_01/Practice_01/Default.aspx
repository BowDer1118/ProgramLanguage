<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="Practice_01.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <style type="text/css">
        .auto-style1 {
            color: #0099FF;
            background-color: #66FF33;
        }
        .auto-style2 {
            width: 100%;
            height: 99px;
            position: absolute;
            top: 74px;
            left: 10px;
        }
        .auto-style3 {
            width: 28px;
        }
        .auto-style4 {
            text-align: center;
        }
        .auto-style5 {
            margin-left: 25px;
        }
    </style>
</head>
<body style="background-image: url('web_background.jpg'); background-repeat: no-repeat; background-attachment: fixed; background-position: center center ;background-size:cover">
    <form id="form1" runat="server">
        <div class="auto-style1" style="text-align: center">
            <h1>歡迎來到我的網站</h1>
        </div>
        <table class="auto-style2" style="z-index: 1">
            <tr>
                <td class="auto-style3">&nbsp;</td>
                <td class="auto-style4">
                    <asp:Label ID="account" runat="server" Text="帳號:"></asp:Label>
                    <asp:TextBox ID="accountTB" runat="server" CssClass="auto-style5"></asp:TextBox>
                </td>
                <td>&nbsp;</td>
            </tr>
            <tr>
                <td class="auto-style3">&nbsp;</td>
                <td class="auto-style4">
                    <asp:Label ID="password" runat="server" Text="密碼:"></asp:Label>
                    <asp:TextBox ID="passwordTB" runat="server" CssClass="auto-style5"></asp:TextBox>
                </td>
                <td>&nbsp;</td>
            </tr>
            <tr>
                <td class="auto-style3">&nbsp;</td>
                <td class="auto-style4">
                    <asp:Button ID="loginBT" runat="server" Text="登入" />
                    <asp:LinkButton ID="entryLB" runat="server">進入網站</asp:LinkButton>
                </td>
                <td>&nbsp;</td>
            </tr>
        </table>
    </form>
</body>
</html>
