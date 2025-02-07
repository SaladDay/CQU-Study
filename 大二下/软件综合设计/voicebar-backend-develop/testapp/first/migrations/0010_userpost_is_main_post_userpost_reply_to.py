# Generated by Django 4.1 on 2022-08-12 19:18

from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    dependencies = [
        ('first', '0009_alter_userpost_user'),
    ]

    operations = [
        migrations.AddField(
            model_name='userpost',
            name='is_main_post',
            field=models.BooleanField(default=False),
        ),
        migrations.AddField(
            model_name='userpost',
            name='reply_to',
            field=models.ForeignKey(blank=True, null=True, on_delete=django.db.models.deletion.CASCADE, to='first.userpost'),
        ),
    ]
