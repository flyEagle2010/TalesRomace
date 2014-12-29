<GameProjectFile>
  <PropertyGroup Type="Scene" Name="LoginScene" ID="c9c4ebad-f9ca-467f-9cf0-6b37757d5487" Version="2.0.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1.0000" />
      <ObjectData Name="Scene" FrameEvent="" ctype="SingleNodeObjectData">
        <Position X="0.0000" Y="0.0000" />
        <Scale ScaleX="1.0000" ScaleY="1.0000" />
        <AnchorPoint />
        <CColor A="255" R="255" G="255" B="255" />
        <Size X="1136.0000" Y="640.0000" />
        <PrePosition X="0.0000" Y="0.0000" />
        <PreSize X="0.0000" Y="0.0000" />
        <Children>
          <NodeObjectData Name="bg" ActionTag="40" FrameEvent="" Tag="25" ObjectIndex="2" ctype="SpriteObjectData">
            <Position X="568.0000" Y="320.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <CColor A="255" R="255" G="255" B="255" />
            <Size X="1136.0000" Y="640.0000" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="PlistSubImage" Path="background.png" Plist="login.plist" />
          </NodeObjectData>
          <NodeObjectData Name="serverPage" ActionTag="41" Visible="False" FrameEvent="" Tag="26" ObjectIndex="1" TouchEnable="True" BackColorAlpha="102" ComboBoxIndex="1" ColorAngle="90.0000" ctype="PanelObjectData">
            <Position X="0.0000" Y="0.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <AnchorPoint />
            <CColor A="255" R="255" G="255" B="255" />
            <Size X="1136.0000" Y="640.0000" />
            <PrePosition X="0.0000" Y="0.0000" />
            <PreSize X="1.0000" Y="1.0000" />
            <Children>
              <NodeObjectData Name="serverBg" ActionTag="39" FrameEvent="" Tag="24" ObjectIndex="1" ctype="SpriteObjectData">
                <Position X="568.0000" Y="320.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <CColor A="255" R="255" G="255" B="255" />
                <Size X="835.0000" Y="533.0000" />
                <PrePosition X="0.5000" Y="0.5000" />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="PlistSubImage" Path="login_account login_plank_1.png" Plist="login.plist" />
              </NodeObjectData>
              <NodeObjectData Name="serverList" ActionTag="48" FrameEvent="" Tag="33" ObjectIndex="1" TouchEnable="True" BackColorAlpha="102" ComboBoxIndex="1" ColorAngle="90.0000" ScrollDirectionType="Vertical" ctype="ScrollViewObjectData">
                <Position X="182.5000" Y="86.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <AnchorPoint />
                <CColor A="255" R="255" G="255" B="255" />
                <Size X="230.0000" Y="400.0000" />
                <PrePosition X="0.1607" Y="0.1344" />
                <PreSize X="0.2025" Y="0.6250" />
                <Children>
                  <NodeObjectData Name="btn_serverGroup" ActionTag="56" FrameEvent="" Tag="301" ObjectIndex="2" TouchEnable="True" FontSize="24" ButtonText="" Scale9Width="188" Scale9Height="50" ctype="ButtonObjectData">
                    <Position X="118.0000" Y="415.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <Size X="188.0000" Y="50.0000" />
                    <PrePosition X="0.5130" Y="0.9222" />
                    <PreSize X="0.0000" Y="0.0000" />
                    <TextColor A="255" R="255" G="255" B="255" />
                    <DisabledFileData Type="Default" Path="Default/Button_Disable.png" />
                    <PressedFileData Type="PlistSubImage" Path="login_account login_plank_3.png" Plist="login.plist" />
                    <NormalFileData Type="PlistSubImage" Path="login_account login_plank_2.png" Plist="login.plist" />
                  </NodeObjectData>
                </Children>
                <SingleColor A="255" R="255" G="150" B="100" />
                <FirstColor A="255" R="255" G="150" B="100" />
                <EndColor A="255" R="255" G="255" B="255" />
                <ColorVector ScaleY="1.0000" />
                <InnerNodeSize Width="230" Height="450" />
              </NodeObjectData>
              <NodeObjectData Name="btn_server" ActionTag="57" FrameEvent="" Tag="42" ObjectIndex="3" TouchEnable="True" FontSize="24" ButtonText="内网" Scale9Width="227" Scale9Height="58" ctype="ButtonObjectData">
                <Position X="600.0000" Y="426.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <CColor A="255" R="255" G="255" B="255" />
                <Size X="227.0000" Y="58.0000" />
                <PrePosition X="0.5282" Y="0.6656" />
                <PreSize X="0.0000" Y="0.0000" />
                <TextColor A="255" R="255" G="255" B="255" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" />
                <PressedFileData Type="PlistSubImage" Path="login_account login_plank_7.png" Plist="login.plist" />
                <NormalFileData Type="PlistSubImage" Path="login_account login_plank_4.png" Plist="login.plist" />
              </NodeObjectData>
              <NodeObjectData Name="lastServerTxt" ActionTag="59" FrameEvent="" Tag="44" ObjectIndex="1" FontSize="24" LabelText="内网" IsCustomSize="True" HorizontalAlignmentType="HT_Center" VerticalAlignmentType="VT_Center" ctype="TextObjectData">
                <Position X="750.5000" Y="507.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <CColor A="255" R="255" G="255" B="255" />
                <Size X="200.0000" Y="28.0000" />
                <PrePosition X="0.6607" Y="0.7922" />
                <PreSize X="0.1761" Y="0.0437" />
              </NodeObjectData>
            </Children>
            <SingleColor A="255" R="150" G="200" B="255" />
            <FirstColor A="255" R="150" G="200" B="255" />
            <EndColor A="255" R="255" G="255" B="255" />
            <ColorVector ScaleY="1.0000" />
          </NodeObjectData>
          <NodeObjectData Name="accountPage" ActionTag="42" FrameEvent="" Tag="27" ObjectIndex="2" TouchEnable="True" BackColorAlpha="0" ComboBoxIndex="1" ColorAngle="90.0000" Scale9Width="565" Scale9Height="472" ctype="PanelObjectData">
            <Position X="568.0000" Y="320.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <CColor A="255" R="255" G="255" B="255" />
            <Size X="1136.0000" Y="640.0000" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="0.0000" Y="0.0000" />
            <Children>
              <NodeObjectData Name="btn_login" ActionTag="44" FrameEvent="" Tag="100" ObjectIndex="1" TouchEnable="True" FontSize="48" ButtonText="" Scale9Width="174" Scale9Height="70" ctype="ButtonObjectData">
                <Position X="568.0000" Y="135.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <CColor A="255" R="255" G="255" B="255" />
                <Size X="174.0000" Y="70.0000" />
                <PrePosition X="0.5000" Y="0.2109" />
                <PreSize X="0.0000" Y="0.0000" />
                <TextColor A="255" R="0" G="0" B="0" />
                <DisabledFileData Type="PlistSubImage" Path="login_in_1.png" Plist="login.plist" />
                <PressedFileData Type="PlistSubImage" Path="login_in_2.png" Plist="login.plist" />
                <NormalFileData Type="PlistSubImage" Path="login_in_1.png" Plist="login.plist" />
              </NodeObjectData>
              <NodeObjectData Name="accountTxt" ActionTag="45" FrameEvent="" Tag="30" ObjectIndex="1" TouchEnable="True" FontSize="36" IsCustomSize="True" LabelText="" PlaceHolderText="输入账号" MaxLengthText="10" ctype="TextFieldObjectData">
                <Position X="622.5000" Y="338.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <AnchorPoint ScaleX="0.4980" ScaleY="0.5000" />
                <CColor A="255" R="255" G="255" B="255" />
                <Size X="350.0000" Y="60.0000" />
                <PrePosition X="0.5480" Y="0.5281" />
                <PreSize X="0.3081" Y="0.0938" />
              </NodeObjectData>
              <NodeObjectData Name="passTxt" ActionTag="46" FrameEvent="" Tag="31" ObjectIndex="2" TouchEnable="True" FontSize="36" IsCustomSize="True" LabelText="" PlaceHolderText="输入密码" MaxLengthText="10" PasswordEnable="True" ctype="TextFieldObjectData">
                <Position X="622.5000" Y="233.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <AnchorPoint ScaleX="0.4980" ScaleY="0.5000" />
                <CColor A="255" R="255" G="255" B="255" />
                <Size X="350.0000" Y="60.0000" />
                <PrePosition X="0.5480" Y="0.3641" />
                <PreSize X="0.3081" Y="0.0938" />
              </NodeObjectData>
            </Children>
            <FileData Type="PlistSubImage" Path="login_account login_3.png" Plist="login.plist" />
            <SingleColor A="255" R="150" G="200" B="255" />
            <FirstColor A="255" R="150" G="200" B="255" />
            <EndColor A="255" R="255" G="255" B="255" />
            <ColorVector ScaleY="1.0000" />
          </NodeObjectData>
          <NodeObjectData Name="regPage" ActionTag="-2126285907" FrameEvent="" Tag="18" ObjectIndex="4" TouchEnable="True" BackColorAlpha="0" ComboBoxIndex="1" ColorAngle="90.0000" Scale9Width="565" Scale9Height="472" ctype="PanelObjectData">
            <Position X="568.0000" Y="320.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <CColor A="255" R="255" G="255" B="255" />
            <Size X="1136.0000" Y="640.0000" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="0.0000" Y="0.0000" />
            <Children>
              <NodeObjectData Name="btn_reg" ActionTag="-1647587769" FrameEvent="" Tag="101" ObjectIndex="5" TouchEnable="True" FontSize="36" ButtonText="注册" Scale9Width="93" Scale9Height="93" ctype="ButtonObjectData">
                <Position X="568.0000" Y="135.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <CColor A="255" R="255" G="255" B="255" />
                <Size X="93.0000" Y="93.0000" />
                <PrePosition X="0.0000" Y="0.0000" />
                <PreSize X="0.0000" Y="0.0000" />
                <TextColor A="255" R="255" G="255" B="255" />
                <DisabledFileData Type="PlistSubImage" Path="BtnReturn_0.png" Plist="common.plist" />
                <PressedFileData Type="PlistSubImage" Path="BtnReturn_2.png" Plist="common.plist" />
                <NormalFileData Type="PlistSubImage" Path="BtnReturn_1.png" Plist="common.plist" />
              </NodeObjectData>
              <NodeObjectData Name="accountTxt" ActionTag="629893593" FrameEvent="" Tag="20" ObjectIndex="3" TouchEnable="True" FontSize="36" IsCustomSize="True" LabelText="" PlaceHolderText="输入账号" MaxLengthText="10" ctype="TextFieldObjectData">
                <Position X="622.5000" Y="338.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <AnchorPoint ScaleX="0.4980" ScaleY="0.5000" />
                <CColor A="255" R="255" G="255" B="255" />
                <Size X="350.0000" Y="60.0000" />
                <PrePosition X="0.0000" Y="0.0000" />
                <PreSize X="0.0000" Y="0.0000" />
              </NodeObjectData>
              <NodeObjectData Name="passTxt" ActionTag="-1545460336" FrameEvent="" Tag="21" ObjectIndex="4" TouchEnable="True" FontSize="36" IsCustomSize="True" LabelText="" PlaceHolderText="输入密码" MaxLengthText="10" PasswordEnable="True" ctype="TextFieldObjectData">
                <Position X="622.5000" Y="233.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <AnchorPoint ScaleX="0.4980" ScaleY="0.5000" />
                <CColor A="255" R="255" G="255" B="255" />
                <Size X="350.0000" Y="60.0000" />
                <PrePosition X="0.0000" Y="0.0000" />
                <PreSize X="0.0000" Y="0.0000" />
              </NodeObjectData>
            </Children>
            <FileData Type="PlistSubImage" Path="login_account login_3.png" Plist="login.plist" />
            <SingleColor A="255" R="150" G="200" B="255" />
            <FirstColor A="255" R="150" G="200" B="255" />
            <EndColor A="255" R="255" G="255" B="255" />
            <ColorVector ScaleY="1.0000" />
          </NodeObjectData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>